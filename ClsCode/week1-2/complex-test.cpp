#include <iostream>     /* File: complex-test.cpp */
using namespace std;
#include "complex.h"

void f(const Complex a) { a.print(); }   // const Complex a  = u
void g(const Complex* a) { a->print(); } // const Complex* a = &u
void h(const Complex& a) { a.print(); }  // const Complex& a = u

int main()
{
    // Check the parameter passing methods
    Complex u(4, 5); f(u); g(&u); h(u);
    
    // Check the parameter returning methods
    Complex w(10, 10); cout << endl << endl;
    Complex x(4, 5); (x.add1(w)).print();    // Complex  temp = *this = x
    Complex y(4, 5); (y.add2(w))->print();   // Complex* temp =  this = &y
    Complex z(4, 5); (z.add3(w)).print();    // Complex& temp = *this = z

    cout << endl << endl;          // What is the output now?
    Complex a(4, 5); a.add1(w).add1(w).print();   a.print(); cout << endl;
    Complex b(4, 5); b.add2(w)->add2(w)->print(); b.print(); cout << endl;
    Complex c(4, 5); c.add3(w).add3(w).print();   c.print();

    /*
    Complex val1(1.0f, 2.0f);
    Complex val2(0.0f, 0.0f);
    Complex& ref1 = val1.add1(val2); 
    // error: initial value of reference to non-const must be an lvalue C/C++(461)
    // Complex val1
    -> means the object returned by add1 is NOT a valid lvalue -> it is a temp object and camnot be attached to a reference
    */

    /*
    Complex val1(1.0f, 2.0f);
    Complex val2(0.0f, 0.0f);
    Complex* ptr = &val1.add1(val2); 
    ptr->print();
    // error: taking address of rvalue [-fpermissive]
    // 42 |     Complex* ptr = &val1.add1(val2);
    //    |               
    // the TEMP object returned by add1 is regarded as rvalue (not a valid lvalue)
    */

    /* THIS IS OK!
    Complex val1(1.0f, 2.0f);
    Complex val2(0.0f, 0.0f);
    Complex* ptr = &val1.add3(val2); 
    ptr->print();
    */

    return 0;
}

// execution result:
/*
(4 , 5)
(4 , 5)
(4 , 5)


(14 , 15)
(14 , 15)
(14 , 15)


(24 , 25)
(14 , 15) -> the second addition works on the TEMP object, it does not reflect on (a)

(24 , 25)
(24 , 25)

(24 , 25)
(24 , 25)
*/