#include <iostream>                    /* File: utils-namespace.cpp */
using namespace std;
#include "ms-utils-namespace.h"
#include "apple-utils-namespace.h"  
namespace ms = microsoft;              // Namespace alias
enum class OS { MSWindows, MacOS } choice;

int main() 
{
    apple::Some_Class sc; apple::Stack apple_stack; 
    ms::Other_Class oc; ms::Stack ms_stack;
    ms::app(42);

    cout << "Input your OS choice: ";
    int int_choice; cin >> int_choice; // Can't cin to choice. Why?
    switch (choice = static_cast<OS>(int_choice))
    {
        case OS::MSWindows: ms::edge(); break;
        case OS::MacOS: apple::safari(); break;
        default: cerr << "Unsupported OS" << endl;
    }
    return 0;
}
