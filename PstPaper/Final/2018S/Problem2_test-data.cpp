/* File: test-data.cpp */
#include "Problem2_data.h"

Derived *Derived::instance;
int Base::d{0};
int Derived::d{10};

int main()
{
    Base base;
    Derived *drv1 = Derived::getInstance();
    Derived *drv2 = Derived::getInstance();
    drv2->print();
    Derived::destroy();
    drv2->destroy();
    return 0;
}

/*
(a) [4 points] Write down the output from Line 13 in test-data.cpp.
    as singleton design, drv1 = drv2
    a = 3   -> a and b in global scope
    b = 3
    c = 1   -> c and d in Base scope (d is 'global' static)
    d = 2

(b) [4 points] The function destroy() at Lines 15-16 in test-data.cpp has not been
declared nor implemented. Tell us where and how you would declare and implement
destroy(). You may design it in any way (e.g., member function, static function, friend
function, global function, etc.) you see fit. Except for your designed destroy() function,
you are not allowed to modify any other part of the whole program.
    static void destroy(void)
    {
        if (instance != nullptr)
            delete instance;
            instance = nullptr;
        return;
    }
*/