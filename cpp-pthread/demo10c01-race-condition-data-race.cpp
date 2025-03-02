
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

int coutner = 0;

void* increase(void*){
    sleep(1);
    for(int i=0; i<1000; i++) coutner++;
    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    constexpr int NUM_THREADS = 16;
    pthread_t lstTid[NUM_THREADS];
    int ret = 0;

    for (int i = 0; i < NUM_THREADS; ++i) ret = pthread_create(&lstTid[i], nullptr, &increase, nullptr);
    for (int i = 0; i < NUM_THREADS; ++i) ret = pthread_join(lstTid[i], nullptr);

    cout << "counter = " << coutner << endl;
    return 0;
}