
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::mutex mut;
std::condition_variable conditionVar;

constexpr int NUM_TH_FOO = 3;

void foo() {
    cout << "foo is waiting..." << endl;

    std::unique_lock<std::mutex> mutLock(mut);
    conditionVar.wait(mutLock);

    cout << "foo resumed" << endl;
}


void bar() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    conditionVar.notify_all();
    
    // for (int i = 0; i < NUM_TH_FOO; ++i) {
    //     std::this_thread::sleep_for(std::chrono::seconds(2));
    //     conditionVar.notify_one();
    // }
}


int main() {
    std::thread lstThFoo[NUM_TH_FOO];

    for (auto&& thFoo : lstThFoo)  thFoo = std::thread(&foo);
    auto thBar = std::thread(&bar);
    for (auto&& thFoo : lstThFoo) thFoo.join();
    thBar.join();

    return 0;
}