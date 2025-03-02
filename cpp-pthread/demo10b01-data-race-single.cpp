
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <cstdlib>

using namespace std;

int *a = nullptr;
int N = 0;

int getResult(){
    a = (int*)calloc(sizeof(int), N+1);
    for (int i = 1; i <= N; ++i)
        if (0 == i % 2 || 0 == i % 3) a[i] = 1;

    int result = 0;

    for (int i = 1; i <= N; ++i)
        if (a[i]) ++result;
    free(a);
    a = nullptr;
    return result;
}



int main(){
    N = 8;
    int result = getResult();
    cout << "Numbers of integers that are divisible by 2 or 3 is: " << result << endl;

    return 0;
}

