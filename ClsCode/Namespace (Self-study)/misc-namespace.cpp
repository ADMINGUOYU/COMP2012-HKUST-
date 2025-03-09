#include <iostream>     /* File: misc-namespace.cpp */

namespace hkust
{
    namespace cse { int rank() { return 1; } } // Nested namespace
    void good() { std::cout << "Good!" << std::endl; }
}

namespace hkust   // Extend the namespace
{
    void school() { std::cout << "School!" << std::endl; }
}

int main()
{ 
    std::cout << "CSE's rank: " << hkust::cse::rank() << std::endl;
    hkust::good();
    hkust::school(); return 0;
}
