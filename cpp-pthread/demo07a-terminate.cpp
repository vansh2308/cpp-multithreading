
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

volatile bool is_running;

void* do_task(void*){
    while(is_running){
        cout << "Running..." << endl;
        sleep(2);
    }

    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid;
    is_running = true;
    pthread_create(&tid, nullptr, &do_task, nullptr);

    sleep(5);
    is_running = false;

    pthread_join(tid, nullptr);
    return 0;
}