
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void* do_task(void*){
    cout << "Hello\n";
    sleep(3);
    cout << "Bye\n";

    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid;
    int ret = pthread_create(&tid, nullptr, &do_task, nullptr);
    pthread_join(tid, nullptr);

    return 0;
}