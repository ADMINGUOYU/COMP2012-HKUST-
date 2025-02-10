// ********************************************* //
// This file is meant for separate testing ONLY! //
// ********************************************* //

#include <iostream>

int main(int argc, char* argv[])
{
    int a = {1} ,b = {1} ,c = {1};

    auto lambda = [a,b,c](void)->void
        {
            a++;
            std::cout << "a = " << a << std::endl;
            std::cout << "b = " << b << std::endl;
            std::cout << "c = " << c << std::endl;
        };

    lambda();

    for(int i : {1, 4, 22, 19})
    {
        a += i;
        b *= i;
        c = a * b;
    }
    
    lambda();

    return 0;
}