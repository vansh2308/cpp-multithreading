
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void* foo(void*) {
    cout << "foo is starting..." << endl;
    sleep(2);
    cout << "foo is exiting..." << endl;

    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid;
    int ret = pthread_create(&tid, nullptr, &foo, nullptr);
    ret = pthread_detach(tid);

    if (ret) {
        cout << "Error: Cannot detach tidFoo" << endl;
    }

    sleep(1);
    cout << "Main thread exiting....\n";

    return 0;
}