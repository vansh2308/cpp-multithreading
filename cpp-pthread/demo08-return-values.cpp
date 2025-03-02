
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

struct thread_arg{
    int val;
    int res;
} typedef thread_arg;

void* do_task(void* args){
    int val = *(int*)args;
    int* res = new int;
    *res = val*2;

    pthread_exit((void*) res);
    return (void*) res;

    // thread_arg* arg = (thread_arg*) args;
    // (arg->res) = 2*arg->val;
    // cout << arg->val << " " << arg->res << endl;

    // pthread_exit(nullptr);
    // return nullptr;
}


int main(){
    pthread_t tid;
    int val = 5;
    int* res = nullptr;

    pthread_create(&tid, nullptr, &do_task, &val);
    pthread_join(tid, (void**)&res);
    cout << *res << endl;

    return 0;
}
