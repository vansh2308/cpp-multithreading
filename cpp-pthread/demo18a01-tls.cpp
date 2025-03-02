

#include <iostream>
#include <string>
#include <thread>
using namespace std;

thread_local string value = "NOT SET";

void doTask() {
    cout << value << endl;
}

int main() {
    value = "APPLE";
    auto th = std::thread(&doTask);
    cout << value << endl;
    th.join();

    return 0;
}