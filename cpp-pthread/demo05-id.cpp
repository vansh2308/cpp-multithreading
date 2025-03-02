
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void* do_task(void*){
    sleep(2);
    cout << pthread_self() << endl;
    
    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid_foo, tid_bar;
    pthread_create(&tid_foo, nullptr, &do_task, nullptr);
    pthread_create(&tid_bar, nullptr, &do_task, nullptr);

    cout << tid_foo << endl;
    cout << tid_bar << endl;

    pthread_join(tid_foo, nullptr);
    pthread_join(tid_bar, nullptr);

    return 0;
}