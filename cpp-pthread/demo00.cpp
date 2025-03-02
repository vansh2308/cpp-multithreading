
#include <iostream>
#include <pthread.h>

using namespace std;

void* do_task(void*){
    for(int i=0; i<300; i++) cout << "B";

    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid;
    int ret;

    ret = pthread_create(&tid, nullptr, &do_task, nullptr);
    for(int i=0; i<300; i++) cout << 'A';

    pthread_join(tid, nullptr);
    cout << endl;
    return 0;
}