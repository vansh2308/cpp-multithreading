
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void* foo(void*){
    cout << "foo starting...\n";

    if(int ret = pthread_detach(pthread_self())){
        cout << "Error: Cannot detach" << endl;
    }

    sleep(2);

    cout << "foo ending...\n";
    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid;
    int ret = pthread_create(&tid, nullptr, &foo, nullptr);

    sleep(1);
    cout << "Main exiting...\n";

    return 0;
}