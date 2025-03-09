#include <iostream>     /* File: const-char-ptrs2.cpp */
using namespace std;

int main()
{
    char s[] = "COMP2012"; // Usual initialization in the past
    char p[] {"MATH1013"}; // C++11 style of uniform initialization

    const char* pcc {s};   // Pointer to constant char
    pcc[5] = '5';          // Error! expression must be a modifiable lvalueC/C++(137) cannot use pcc to modify the content it points to
    pcc = p;               // OK, but what does that mean?

    char *const cpc = s;   // Constant pointer
    cpc[5] = '5';          // OK
    cpc = p;               // Error! expression must be a modifiable lvalueC/C++(137) this is a constant pointer -> which means you cannot modify the value of that pointer

    const char *const cpcc = s; // const pointer to const char
    cpcc[5] = '5';         // Error!
    cpcc = p;              // Error!
    return 0;
}
