#include <iostream>       /* File: utils-using.cpp */
using namespace std;
#include "ms-utils-namespace.h"
#include "apple-utils-namespace.h"
namespace ms = microsoft; // Namespace alias
using apple::Some_Class;
using ms::Other_Class;
using apple::Stack;
using ms::app;

int main() 
{
    Some_Class sc;        // Refer to apple::Some_Class
    Other_Class oc;       // Refer to ms::Other_Class
    Stack apple_stack;    // Refer to apple::Stack
    ms::Stack ms_stack;
    app(2); return 0;     // Refer to ms::app
}
