#include <iostream>
using namespace std;

class Base
{
private:
    int *p{nullptr};

public:
    Base() = default;
    Base(int n = 0)
    { //****Assumeline#9hasNOerror.****
        p = (n) ? new int[n] : new int;
    }
    ~Base()
    {
        delete[] p; //****Assumeline#13hasNOerror.****
    }
};

class Derived : public Base
{
private:
    int d(1);
    int *p = nullptr;

public:
    Derived() : p(new int) { }
    Derived(int n, int d) : Base(n), d(d), p(new int) {}
    Derived(const Derived & d) = delete; //****Assumeline#24hasNOerror.****
    Derived &func(Derived & d)
    {
        d.d = 10;
        return *this;
    }
    ~Derived() { delete p; }
};

int main()
{
    Base b{2};
    Derived d1(1, 2);
    Derived d2(d1);
    Derived d3(2, 4);
    Derived d4 = d3.func(d2);
    Base *bPtr = new Derived;
    delete bPtr;
    return 0;
}

// d(1) is interpreted as: int Derived::d(<error type>)
// That is not cool~

/*
test.cpp:27:11: error: expected identifier before numeric constant
   27 |     int d(1);
      |           ^
test.cpp:27:11: error: expected ‘,’ or ‘...’ before numeric constant
test.cpp: In constructor ‘Derived::Derived()’:
test.cpp:31:26: error: call of overloaded ‘Base()’ is ambiguous
   31 |     Derived() : p(new int) { }
      |                          ^
test.cpp:14:5: note: candidate: ‘Base::Base(int)’
   14 |     Base(int n = 0)
      |     ^~~~
test.cpp:13:5: note: candidate: ‘constexpr Base::Base()’
   13 |     Base() = default;
      |     ^~~~
test.cpp: In constructor ‘Derived::Derived(int, int)’:
test.cpp:32:38: error: class ‘Derived’ does not have any field named ‘d’
   32 |     Derived(int n, int d) : Base(n), d(d), p(new int) {}
      |                                      ^
test.cpp: In member function ‘Derived& Derived::func(Derived&)’:
test.cpp:36:11: error: invalid use of member function ‘int Derived::d(int)’ (did you forget the ‘()’ ?)
   36 |         d.d = 10;
      |         ~~^
test.cpp: In function ‘int main()’:
test.cpp:46:18: error: use of deleted function ‘Derived::Derived(const Derived&)’
   46 |     Derived d2(d1);
      |                  ^
test.cpp:33:5: note: declared here
   33 |     Derived(const Derived & d) = delete; //****Assumeline#24hasNOerror.****
      |     ^~~~~~~
test.cpp:48:28: error: use of deleted function ‘Derived::Derived(const Derived&)’
   48 |     Derived d4 = d3.func(d2);
      |                            ^
test.cpp:33:5: note: declared here
   33 |     Derived(const Derived & d) = delete; //****Assumeline#24hasNOerror.****
      |     ^~~~~~~
*/