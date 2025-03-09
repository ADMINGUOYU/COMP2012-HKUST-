#include <iostream>     /* File: std-per-obj-using.cpp */
using std::string;
using std::cin;
using std::cout;
using std::endl;


int main()
{
    string s;
    cin >> s;
    cout << s << endl;

    s += " is good!";
    cout << s << endl;
    
    return 0;
}
