#include <iostream>     /* File: assignable.cpp */
using namespace std;

int square(int x) { return x*x; }
string wrap(const string& s) { return "begin." + s + ".end";  }

int main()
{
    int a  = square(5);                               // Assignable?
    int& b = square(5); cout << b << endl;            // Assignable? -> initial value of reference to non-const must be an lvalueC/C++(461)
    const int& c = square(5); cout << c << endl;      // Assignable?
    cout << (square(5) = 25) << endl;                 // Assignable? -> expression must be a modifiable lvalueC/C++(137)

    string s1 = wrap("x"); cout << s1 << endl;        // Assignable?
    string& s2 = wrap("x"); cout << s2 << endl;       // Assignable? -> initial value of reference to non-const must be an lvalueC/C++(461)
    const string& s3 = wrap("x"); cout << s3 << endl; // Assignable?
    cout << (wrap("x") = "y") << endl;                // Assignable?
    return 0;
}
