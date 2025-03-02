
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void* do_task(void* args){
    int idx = *(int*)args;
    cout << idx;
    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    constexpr int NUM_THREADS = 5;
    pthread_t lst_tid[NUM_THREADS];
    int lst_args[NUM_THREADS];

    for(int i=0; i<NUM_THREADS; i++){
        lst_args[i] = i+1;
        pthread_create(&lst_tid[i], nullptr, &do_task, &lst_args[i]);
    }

    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(lst_tid[i], nullptr);
    }

    cout << endl;
    return 0;
}