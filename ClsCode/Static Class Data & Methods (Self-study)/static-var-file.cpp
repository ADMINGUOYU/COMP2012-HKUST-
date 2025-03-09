#include <iostream>     /* File: static-var-file.cpp */
using namespace std;

// Global but static variables can be only used
// in the current file; no external linkage
static int x = 5;

int f() { return ++x; }

int main()
{
    cout << x << endl;
    cout << f() << endl;
    cout << f() << endl;

    return 0;
}
