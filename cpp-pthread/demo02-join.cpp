
#include <iostream>
#include <pthread.h>

using namespace std;

void* do_heavy_task(void*){
    for (int i = 0; i < 2000000000; ++i);
    cout << "Done!" << endl;

    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid;
    int ret = pthread_create(&tid, nullptr, &do_heavy_task, nullptr);

    ret = pthread_join(tid, nullptr);
    cout << "Bye\n";
    return 0;
}