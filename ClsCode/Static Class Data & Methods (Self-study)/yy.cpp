#include <iostream>     /* File: static-var-file.cpp */
using namespace std;

class A
{
  private:
    const static int x;

  public:
    A() {}
    void print() const { cout << x << endl; }
    
};

const int A::x = 20;


int main()
{
    A a;
    
    a.print();
    return 0;
}
    
