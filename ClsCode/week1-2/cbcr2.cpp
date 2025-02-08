#include <iostream>
using namespace std;
void cbr(int& a) { cout << a << endl; }
void cbcr(const int& a) { cout << a << endl; }
int main() 
{
    int x {50}; const int y {100};
    // Which of the following give(s) compilation error?
    cbr(x);
    cbcr(x);
    // cannot bind a int& typed reference to const int type
    cbr(y);     // error: qualifiers dropped in binding reference of type "int &" to initializer of type "const int"C/C++(433)
    cbcr(y);
    // same error -> 1234 is literal constant, cannot bind it to int& typed reference
    cbr(1234);  // error: initial value of reference to non-const must be an lvalueC/C++(461)
    cbcr(1234);
}
