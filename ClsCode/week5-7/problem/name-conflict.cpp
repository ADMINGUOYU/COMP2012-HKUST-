#include <iostream>     /* File: name-conflict.cpp */
using namespace std;
#include "name-conflict.h"

void smart(const B* p) { cout << "Inside smart(): "; p->f(); } 

int main()
{
    B base(5, 6); cout << endl; 
    D derive; cout << endl;

    B* bp = &base; bp->f(); cout << endl;
    D* dp = &derive; dp->f(); cout << endl; // <- This line prints TWO lines: <Derived class: 10 , 20> AND <Base class: 1 , 2>
    // NOT functions in both classes are called -> void f() const { cout << "Derived class: "; print(x, y); B::f(); }
    bp = &derive; bp->f(); cout << endl;

    cout << "Call smart(bp): "; smart(bp);
    cout << "Call smart(dp): "; smart(dp);
    return 0;
}

/*
OUTPUT:
Base class constructor: 5 , 6

Base class constructor: 1 , 2
Derived class constructor

Base class: 5 , 6

Derived class: 10 , 20
Base class: 1 , 2

Base class: 1 , 2

Call smart(bp): Inside smart(): Base class: 1 , 2
Call smart(dp): Inside smart(): Base class: 1 , 2
*/