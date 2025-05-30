#include <iostream>     /* File: default-assign-problem1.cpp */
#include <cstring> 
using namespace std;
class Word
{
  private:
    int frequency; char str[100];
    void set(int f, const char* s) { frequency = f; strcpy(str, s); }
  public:
    Word(const char* s, int k = 1)
        { set(k, s); cout << "\nMay work as const char* conversion\n"; }
    Word(const Word& w) { set(w.frequency, w.str); cout << "\nCopy\n"; }

    void print() const   // Also prints the address of object's str array
        { cout << str << " : " << frequency << " ; "
               << reinterpret_cast<const void*>(str) << endl; }
};

int main()
{ 
    Word x("rat"); x.print();     // Conversion constructor
    Word y = x;    y.print();     // Copy constructor
    Word z("cat"); z.print();     // Conversion constructor
    z = x;         z.print();     // Default assignment operator
}

/*
Result:
May work as const char* conversion
rat : 1 ; 0x7ffd01425a74

Copy
rat : 1 ; 0x7ffd01425ae4

May work as const char* conversion
cat : 1 ; 0x7ffd01425b54
rat : 1 ; 0x7ffd01425b54

*/
