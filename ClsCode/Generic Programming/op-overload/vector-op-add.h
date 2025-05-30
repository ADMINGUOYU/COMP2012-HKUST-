#include <iostream>     /* File: vector-op-add.h */
class Vector
{
  public:
    Vector(double a = 0, double b = 0) : x(a), y(b) { }
    double getx() const { return x; }
    double gety() const { return y; }
    Vector operator+(const Vector& b) const;
    // actually compiled into :
    // Vector operator+ (const Vector* this, const Vector& b);
    const Vector& operator+=(const Vector& b);
  private:
    double x, y;
};

Vector Vector::operator+(const Vector& b) const
{   // Return by value; any copy constructor?
    // -> yes (refer to temporary objects)
    // -> assume no copy elision applied
    return Vector(x + b.x, y + b.y);
}
const Vector& Vector::operator+=(const Vector& b)
{
    x += b.x; y += b.y;
    return *this; // Return by const reference. Why? -> rvalue only
}
