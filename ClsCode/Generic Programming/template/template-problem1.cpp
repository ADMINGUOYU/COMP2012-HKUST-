#include <iostream>     /* File: template-problem.cpp */
using namespace std;

template <typename T> const T&
larger(const T& a, const T& b) { return (a < b) ? b : a; }
// add "printf("a: %d, b: %d\n", a, b);" here

int main()
{
    char a[16], b[16];
    cin >> a >> b;

    cout << larger(a, b) << " is better!" << endl;
    return 0;
}

// 1st trial, enter: apple microsoft. What is the result?
// -> apple microsoft
// -> a: 21456304, b: 21456320
// -> microsoft is better!
// 2nd trial, enter: microsoft apple. What is the result?
// -> microsoft apple
// -> a: 37774608, b: 37774624
// -> apple is better!

/*
name of an array (cstring) is a pointer (slightly different)
when pass-by-reference, the size info is kept
-> char (&str) [16]

The reason of the printing is:
-> instead of comparing the string, we are comparing the address
-> operator< of std::string is well defined
*/