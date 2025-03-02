
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

volatile bool is_running;

void do_task(){
    while(is_running){
        cout << "Running...\n";
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int main(){
    is_running = true;
    auto th = thread(&do_task);
    this_thread::sleep_for(chrono::seconds(6));

    is_running = false;
    th.join();
    return 0;
}