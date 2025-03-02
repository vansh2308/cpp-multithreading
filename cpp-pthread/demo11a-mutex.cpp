
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int ctr = 0;

void* do_task(void*){
    sleep(1);

    // int ret = pthread_mutex_trylock(&mut);
    // if (ret) {
    //     switch (ret) {
    //         case EBUSY:
    //             The mutex could not be acquired because the mutex pointed to by mutex
    //             was already locked.

    //         case EAGAIN:
    //             The mutex could not be acquired because the maximum number
    //             of recursive locks for mutex has been exceeded.

    //         case EOWNERDEAD:
    //             The last owner of this mutex died while holding the mutex.
    //             This mutex is now owned by the caller.
    //             The caller must attempt to make the state protected by the mutex consistent.

    //         case ENOTRECOVERABLE:
    //             The mutex you are trying to acquire is protecting state left irrecoverable
    //             by the mutex's previous owner that died while holding the lock.
    //             The mutex has not been acquired.
    //             This condition can occur when the lock was previously acquired
    //             with EOWNERDEAD and the owner was unable to cleanup the state and
    //             had unlocked the mutex without making the mutex state consistent.

    //         case ENOMEM:
    //             The limit on the number of simultaneously held mutexes has been exceeded.
    //     }

    //     pthread_exit(nullptr);
    //     return nullptr;
    // }

    pthread_mutex_lock(&mtx);
    for(int i=0; i<1000; i++) ctr++;
    pthread_mutex_unlock(&mtx);

    pthread_exit(nullptr);
    return nullptr;
}

int main(){
    constexpr int NUM_THREADS = 16;
    pthread_t lst_tid[NUM_THREADS];
    for(int i=0; i<NUM_THREADS; i++) pthread_create(&lst_tid[i], nullptr, &do_task, nullptr);
    for(int i=0; i<NUM_THREADS; i++) pthread_join(lst_tid[i], nullptr);

    pthread_mutex_destroy(&mtx);

    cout << "Counter: " << ctr << endl;
    return 0;
}