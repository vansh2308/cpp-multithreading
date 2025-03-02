
#include <iostream>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

mutex mtx;
condition_variable cv;

void foo(){
    cout << "foo is waiting..." << endl;
    unique_lock<mutex> mtx_lock(mtx);
    cv.wait(mtx_lock);
    cout << "foo resumed..." << endl;
}

void bar(){
    this_thread::sleep_for(chrono::seconds(3));
    cv.notify_one();
}

int main(){
    auto t_foo = thread(&foo);
    auto t_bar = thread(&bar);
    t_foo.join();
    t_bar.join();

    return 0;
}