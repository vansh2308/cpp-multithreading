
#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* do_task(void*){
    pthread_mutex_lock(&mtx);
    cout << "Entering first time...\n";

    pthread_mutex_lock(&mtx);
    cout << "Entering Second time...\n";
    pthread_mutex_unlock(&mtx);

    pthread_mutex_unlock(&mtx);
    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid;
    pthread_create(&tid, nullptr, &do_task, nullptr);
    pthread_join(tid, nullptr);

    pthread_mutex_destroy(&mtx);
    return 0;
}