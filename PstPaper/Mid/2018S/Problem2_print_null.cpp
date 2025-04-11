#include <iostream>

int main (void)
{
    char* str = nullptr;
    std::cout << "Printing 'nullptr': " << str << std::endl;
    return 0;
}

/*
Output:
Printing 'nullptr': @ADMINGUOYU ➜ /workspaces/COMP2012-HKUST-/JunkYard (main) $ 

Notice that the '\n' has not been printed
(but the program does not throw any error)

refer to: https://stackoverflow.com/questions/7019454/why-does-stdcout-output-disappear-completely-after-null-is-sent-to-it

*** if changed to:
std::cout << "Printing 'nullptr': " << nullptr << std::endl;
ERROR: more than one operator "<<" matches these operands
nullptr -> (type) nullptr_t
*/