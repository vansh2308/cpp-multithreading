
#include <iostream>
#include <pthread.h>

using namespace std;

void* do_task(void*){
    cout << "Hare krishna\n";
    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid;
    int ret = pthread_create(&tid, nullptr, &do_task,  nullptr);

    if(ret){
        cerr << "Unable to create thread " << ret << endl;
        return 1;
    }

    ret = pthread_join(tid, nullptr);
    return 0;
}