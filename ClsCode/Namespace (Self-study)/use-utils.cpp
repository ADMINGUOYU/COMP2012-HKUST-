#include <iostream>     /* File: use-utils.cpp */
using namespace std;
#include "apple-utils.h"
#include "ms-utils.h"
enum class OS { MSWindows, MacOS } choice;

int main() 
{
    Some_Class sc;
    Other_Class oc;
    
    if (choice == OS::MacOS)
        safari();
    else if (choice == OS::MSWindows)
        edge();
    return 0;
}
