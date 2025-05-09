#include <iostream>
#include <cstring>
using namespace std;

class Foo
{
public:
    Foo()
    {
        a = new char[9];
        strcpy(a, "comp2012");
        c = 100;
    }

    ~Foo() { delete a; }
    void set_b(int b) { Foo::b = b; }
    void set_c(int c) { this->c{c}; }
    int get_b() const { return b; }
    int get_c() const { return c; }

private:
    const char *a;
    int b{10}, c;
};

class Bar
{
public:
    Bar() { obj = new Foo(); }
    ~Bar() { delete obj; }
    const Foo &get_obj() const { return *obj; }
    void modify(int b) const { obj->set_b(b); }

private:
    Foo *obj;
};

void operate(Bar bar) { bar.modify(10); }

int main()
{
    Bar bar;
    Foo *foo = &bar.get_obj();
    operate(bar);
    return 0;
}

/*
The following program contains 5 errors, 3 of which are syntax errors.

|Error#|Line#|                    Description                    |
------------------------------------------------------------------
|  1   | 11  |  strcpy() requires a non-const pointer            |
|  2   | 17  |  cannot use initialization list to assign         |
|  3   | 32  |  cannot call non-const function                   |
|  4   | 43  |  returned obj is const, cannot bind to Foo*       |
|  5   | 44  |  runtime error -> deep copy not performed         |
|  6   | 15  |  10 <-> new and delete mis-match                  |
*/