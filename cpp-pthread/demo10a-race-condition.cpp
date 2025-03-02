
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void* foo(void* arg){
    int val = *(int*)arg;
    sleep(1);
    cout << val;
    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    constexpr int NUM_THREADS = 4;
    pthread_t lst_tid[NUM_THREADS];
    int targs[NUM_THREADS];

    for(int i=0; i<NUM_THREADS; i++){
        targs[i] = i+1;
        int ret = pthread_create(&lst_tid[i], nullptr, &foo, &targs[i]);
    }
    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(lst_tid[i], nullptr);
    }

    cout << endl;
    return 0;
}