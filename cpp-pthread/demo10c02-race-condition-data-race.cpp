

#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

int counter = 0;

void* doTaskA(void*) {
    sleep(1);
    while (counter < 10) ++counter;

    cout << "A won !!!" << endl;
    pthread_exit(nullptr);
    return nullptr;
}

void* doTaskB(void*) {
    sleep(1);
    while (counter > -10) --counter;

    cout << "B won !!!" << endl;
    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid_a, tid_b;
    pthread_create(&tid_a, nullptr, &doTaskA, nullptr);
    pthread_create(&tid_b, nullptr, &doTaskB, nullptr);

    pthread_join(tid_a, nullptr);
    pthread_join(tid_b, nullptr);
    return 0;
}