
#include <iostream>
#include <string>
#include <pthread.h>

using namespace std;

struct thread_arg {
    int x;
    double y;
    string z;
} typedef thread_arg;



void* do_task(void* t_arg){
    thread_arg* arg = (thread_arg*)t_arg;
    printf("(%d, %f, %s)\n", arg->x, arg->y, arg->z.c_str());
    
    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    pthread_t tid;
    thread_arg targ; 
    targ.x = 5; targ.y = 2.5, targ.z = "Hare krishna";

    int ret = pthread_create(&tid, nullptr, &do_task, &targ);
    pthread_join(tid, nullptr);
    return 0;
}