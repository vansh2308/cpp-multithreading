
#include <iostream>
#include <pthread.h>

#define NUM_THREADS 5

using namespace std;

void* do_task(void* tid){
    int id = *(int*)tid;
    cout << "Hello pthread with id = " << id << endl;

    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t lst_tid[NUM_THREADS];
    int targs[NUM_THREADS];
    for(int i=0; i<NUM_THREADS; i++) {
        targs[i] = i+1;
        pthread_create(&lst_tid[i], nullptr, &do_task, &targs[i]);
    }
    
    for(int i=0; i<NUM_THREADS; i++) pthread_join(lst_tid[i], nullptr);
    return 0;
}