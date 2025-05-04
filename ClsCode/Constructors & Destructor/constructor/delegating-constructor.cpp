#include <iostream>     /* File: delegating-constructor.cpp */
#include <cstring>
using namespace std;

class Word              // Modified from copy-constructor.cpp
{
  private:
    int frequency; char* str;
  public:
    Word(const char* s, int f = 1)
    {
        frequency = f; str = new char [strlen(s)+1]; strcpy(str, s);
        cout << "conversion" << endl;
    }
    Word(const Word& w) : Word(w.str, w.frequency) { cout << "copy" << endl; }
    void print() const { cout << str << " : " << frequency << endl; }
};

int main() 
{
    Word movie("Titanic"); movie.print(); // which constructor? -> conversion
    Word song(movie); song.print();       // which constructor? -> copy (first delegated to conversion)
    Word ship = movie; ship.print();      // which constructor? -> copy (first delegated to conversion)
}

/*
OUTPUT:
conversion
Titanic : 1
conversion
copy
Titanic : 1
conversion
copy
Titanic : 1
*/
