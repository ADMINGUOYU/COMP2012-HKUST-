#include "vector-op-index.h" /* File: vector-op-index-test.cpp */

// Replace getx(), gety() by op[]
ostream& operator<<(ostream& os, const Vector& a) // Which op[]?
{
    return (os << '('  << a[0] << " , " << a[1] << ')');
    // if there is no const version of operator[], then this function cannot call a[x]
    // as in this function a is a const reference to Vector object
    // so here, a can only call its member function that is taged 'const'
}
    
int main()
{
    Vector a(1.2, 3.4);
    cout << "Before assignment: " << a << endl;

    a[0] = 5.6; a[1] = 7.8;   // Which op[]?
    cout << "After assignment:  " << a << endl;

    a[2] = 9;                 // Which op[]? Error!
    return 0;
}
