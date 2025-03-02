#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <semaphore>

using namespace std;

auto sem_pkg = counting_semaphore(0);

void make_sheet(){
    for(int i=0; i<4; i++){
        cout << "Make one sheet\n";
        this_thread::sleep_for(chrono::seconds(3));
        sem_pkg.release();
    }
}

void combine_pkg(){
    for(int i=0; i<4; i++){
        sem_pkg.acquire();
        sem_pkg.acquire();
        cout << "Combine 2 sheets into 1 pkg\n";
    }
}


int main(){
    auto th_a = thread(&make_sheet);
    auto th_b = thread(&make_sheet);
    auto th_c = thread(&combine_pkg);

    th_a.join();
    th_b.join();
    th_c.join();

    return 0;
}