#include <iostream>     /* File: test-clock.cpp */
using namespace std;
#include "clock-w-static-fcn.h"

int main()
{
    Clock c1;                       // 0:00
    Clock c2 = Clock::HHMM(123);    // 1:23
    Clock c3 = Clock::minutes(123); // 2:03

    cout << c1 << endl;
    cout << c2 << endl; 
    cout << c3 << endl;

    return 0;
}
