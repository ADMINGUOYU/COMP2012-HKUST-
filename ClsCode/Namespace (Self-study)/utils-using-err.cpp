#include <iostream>             /* File: utils-using-err.cpp */
using namespace std;
#include "ms-utils-namespace.h"
#include "apple-utils-namespace.h"

namespace ms = microsoft;       // Namespace alias
using namespace apple;
using namespace ms;

int main() 
{
    Some_Class sc;              // Refer to apple::Some_Class
    Other_Class oc;             // Refer to ms::Other_Class
    Stack S;                    // Error: ambiguous;
    ms::Stack ms_stack;         // OK
    apple::Stack apple_stack;   // OK
    return 0;
}
