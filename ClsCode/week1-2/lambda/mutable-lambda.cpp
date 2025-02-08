#include <iostream>     /* File : mutable-lambda.cpp */
using namespace std;	

int main()	
{
    int a = 1, b = 2;

    // cout << [a](int x) { return a += x; } (20) << endl; // Error! -> expression must be a modifiable lvalueC/C++(137)
    // [=, &b](int x) mutable   OK
    // [&, b](int x) mutable    OK
    // [=, b](int x) mutable    NOT OK
    // [&, &b](int x) mutable   NOT OK
    cout << [b](int x) mutable { return b *= x; } (20) << endl; // OK!
    cout << "a = " << a << "\tb = " << b << endl;

    return 0;
}

// results:
/*
40
a = 1   b = 2
*/
