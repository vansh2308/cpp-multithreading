
#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* doTask(void*) {
    pthread_mutex_lock(&mtx);
    cout << "First time acquiring the resource" << endl;

    pthread_mutex_lock(&mtx);
    cout << "Second time acquiring the resource" << endl;

    pthread_mutex_unlock(&mtx);
    pthread_mutex_unlock(&mtx);

    pthread_exit(nullptr);
    return nullptr;
}




int main(){
    pthread_t tid;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mtx, &attr);

    pthread_create(&tid, nullptr, &doTask, nullptr);
    pthread_join(tid, nullptr);

    pthread_mutexattr_destroy(&attr);
    pthread_mutex_destroy(&mtx);

    return 0;
}