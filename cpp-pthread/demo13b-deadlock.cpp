
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t mtx_a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mtx_b = PTHREAD_MUTEX_INITIALIZER;

void* task_a(void* arg){
    const char* name = (const char*) arg;
    pthread_mutex_lock(&mtx_a);
    printf("Process %s acquried resource A...\n", name);

    sleep(1);
    pthread_mutex_lock(&mtx_b);
    printf("Process %s acquried resource B...\n", name);
    pthread_mutex_unlock(&mtx_b);
    
    pthread_mutex_unlock(&mtx_a);

    pthread_exit(nullptr);
    return nullptr;
}

void* task_b(void* arg){
    const char* name = (const char*) arg;
    pthread_mutex_lock(&mtx_b);
    printf("Process %s acquried resource B...\n", name);

    sleep(1);
    pthread_mutex_lock(&mtx_a);
    printf("Process %s acquried resource A...\n", name);
    pthread_mutex_unlock(&mtx_a);

    pthread_mutex_unlock(&mtx_b);

    pthread_exit(nullptr);
    return nullptr;
}


int main(){
    pthread_t tid_a, tid_b;
    const char* name_a = "Foo", *name_b = "Bar";

    pthread_create(&tid_a, nullptr, &task_a, &name_a);
    pthread_create(&tid_b, nullptr, &task_b, &name_b);
    pthread_join(tid_a, nullptr);
    pthread_join(tid_b, nullptr);

    pthread_mutex_destroy(&mtx_a);
    pthread_mutex_destroy(&mtx_b);

    cout << "You will never see this statement due to deadlock!" << endl;

    return 0;

}