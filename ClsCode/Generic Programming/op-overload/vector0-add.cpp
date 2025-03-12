#include <iostream>     /* File: vector0-add.cpp */
#include "vector0.h"
Vector add(const Vector& a, const Vector& b)
    { return Vector(a.getx() + b.getx(), a.gety() + b.gety()); }
int main()
{
    Vector a(1, 3), b(-5, 7), c(22), d;
    d = add(add(a, b), c); d.print(); // d = a + b + c
    // Note that you can use a returned temp obj as argument (param) is because we bind 
    // it to a **constant** reference when passing-by-reference.
}
