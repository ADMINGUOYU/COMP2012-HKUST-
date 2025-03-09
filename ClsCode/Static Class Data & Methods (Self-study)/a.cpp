#include <iostream> 
using namespace std;

int g() { cout << "Global g()" << endl; return 1; }

struct X
{
    static int g() { cout << "X::g()" << endl; return 2; }
};


struct Y : public X
{
    static int i;
    static int g() { cout << "Y::g()" << endl; return 3; }
};


int Y::i = g();

int main()
{
    cout << Y::i << endl;
    return 0;
}
    
