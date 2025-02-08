#include <iostream>     /* File : lambda-ref-binding.cpp */
using namespace std;	

int main()	
{
    int a = 1, b = 2, c = 3;
    // type of f -> void f(int x)
    auto f = [&](int x) { a *= x; b += x; c = a + b; };
    //void func(int x) = [&](int x) { a *= x; b += x; c = a + b; };   // error: function "func" may not be initializedC/C++(145)
    
    for (int k = 1; k < 3; f(k++))
        ;
    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;

    a = 11, b = 12, c = 13;
    for (int k = 1; k < 3; f(k++)) // Will f use the new a, b, c?
        ;
    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;

    return 0;
}

// result:
/*
a = 2   b = 5   c = 7
a = 22  b = 15  c = 37
*/

