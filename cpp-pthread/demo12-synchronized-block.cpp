
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

class LockGuard{
    private:
    pthread_mutex_t* mtx = nullptr;
    LockGuard(const LockGuard&) = delete;
    LockGuard(const LockGuard&&) = delete;
    void operator= (const LockGuard&) = delete;
    void operator= (const LockGuard&&) = delete;

    public:
    LockGuard(pthread_mutex_t* mtx){
        this->mtx = mtx;
        pthread_mutex_lock(this->mtx);
    }
    ~LockGuard(){
        pthread_mutex_unlock(this->mtx);
    }
};

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void* do_task(void*){
    sleep(1);
    {
        LockGuard lk(&mtx);
        for(int i=0; i<1000; i++) counter++;
    }

    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    constexpr int NUM_THREADS =16;
    pthread_t lst_tids[NUM_THREADS];
    for(int i=0; i<NUM_THREADS; i++) pthread_create(&lst_tids[i], nullptr, &do_task, nullptr);
    for(int i=0; i<NUM_THREADS; i++) pthread_join(lst_tids[i], nullptr);

    cout << "Counter: " << counter << endl;
    pthread_mutex_destroy(&mtx);

    return 0;
}