
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* do_task(void* arg){
    const char* name = (const char*)arg;
    pthread_mutex_lock(&mtx);
    cout << "Acquired lock...\n";
    // pthread_mutex_unlock(&mtx);

    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tidFoo, tidBar;
    pthread_create(&tidFoo, nullptr, &do_task, (void*)"foo");
    pthread_create(&tidBar, nullptr, &do_task, (void*)"bar");
    
    pthread_join(tidFoo, nullptr);
    pthread_join(tidBar, nullptr);

    cout << "You will never see this statement due to deadlock!" << endl;
    return 0;
}