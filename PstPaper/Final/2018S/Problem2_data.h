/* File: data.h */
#include <iostream>

using namespace std;

int a{0};
static int b{0};

class Base
{
public:
    Base()
    {
        ++a;
        ++b;
        ++c;
        ++d;
    }
    void print() const
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
    }

protected:
    int c{0};
    static int d;
};

// a way of implement Singleton Class
class Derived : public Base
{
public:
    static Derived *getInstance()
    {
        if (instance == nullptr)
            instance = new Derived;
        return instance;
    }

    static void destroy(void);

private:
    // private constructor
    // -> only can create itself by itself
    Derived() : Base()
    {
        ++a;
        ++b;
        ++c;
        ++d;
    }
    ~Derived() {}
    int c{10};
    static int d;
    static Derived *instance;
};