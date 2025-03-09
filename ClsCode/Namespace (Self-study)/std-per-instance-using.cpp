#include <iostream>     /* File: std-per-instance-using.cpp */
using namespace std;

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << s << std::endl;

    s += " is good!";
    std::cout << s << std::endl;
    
    return 0;
}
