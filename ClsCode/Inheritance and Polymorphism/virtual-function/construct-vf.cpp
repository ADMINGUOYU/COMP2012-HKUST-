#include <iostream>     /* File: construct-vf.cpp */
using namespace std;

class Base {
  public:
    Base() { cout << "Base's constructor\n"; f(); }
    virtual void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base {
  public:
    Derived() { cout << "Derived's constructor\n"; }
    virtual void f() override { cout << "Derived::f()" << endl; }
};

int main() {
    Base* p = new Derived;
    cout << "Derived-class object created" << endl;
    p->f();
}

/*
output:

Base's constructor
Base::f()                       <- at this point, the derived object does NOT exist
Derived's constructor
Derived-class object created
Derived::f()                    <- st this point, the derived object is fully initialized
*/