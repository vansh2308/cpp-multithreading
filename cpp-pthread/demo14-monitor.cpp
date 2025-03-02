
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

class Monitor{
    private:
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    int* p_counter = nullptr;
    Monitor(const Monitor&) = delete;
    Monitor(const Monitor&&) = delete;
    void operator= (const Monitor&) = delete;
    void operator= (const Monitor&&) = delete;

    public:

    Monitor (int* p_counter){
        destory();
        this->mtx = PTHREAD_MUTEX_INITIALIZER;
        this->p_counter = p_counter;
    }

    void increase_counter(){
        pthread_mutex_lock(&mtx);
        (*p_counter) += 1;
        pthread_mutex_unlock(&mtx);
    }

    void destory(){
        pthread_mutex_destroy(&this->mtx);
    }
};

void* task(void* arg){
    Monitor* monitor = (Monitor*)arg;
    sleep(1);

    for(int i=0; i<1000; i++) monitor->increase_counter();
    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    int counter = 0;
    Monitor monitor(&counter);

    constexpr int NUM_THREADS = 16;
    pthread_t lst_tids[NUM_THREADS];

    for(int i=0; i<NUM_THREADS; i++) pthread_create(&lst_tids[i], nullptr, &task, (void*)&monitor);
    for(int i=0; i<NUM_THREADS; i++) pthread_join(lst_tids[i], nullptr);

    monitor.destory();
    cout << "Counter: " << counter << endl;

    return 0;
}