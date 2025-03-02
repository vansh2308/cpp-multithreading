
#include <iostream>
#include <memory>
#include <thread>
#include <string>

using namespace std;

thread_local shared_ptr<string> value;

string get_val(){
    if(value.get() == nullptr) value.reset(new string("NOT SET"));
    return *value.get();
}

void do_task(){
    cout << get_val() << endl;
}

int main(){
    value.reset(new string("APPLE"));
    cout << get_val() << endl;

    auto th = thread(&do_task);
    th.join();

    return 0;
}