
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;;

void* do_task(void*){
    while(true){
        cout << "Running...\n" ;
        sleep(2);
    }

    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid;
    pthread_create(&tid, nullptr, &do_task, nullptr);
    
    sleep(5);
    pthread_cancel(tid);
    pthread_join(tid, nullptr);
    return 0;
}