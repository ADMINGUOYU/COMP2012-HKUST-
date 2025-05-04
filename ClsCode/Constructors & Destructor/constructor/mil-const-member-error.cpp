#include <iostream>     /* File: mil-const-member-error.cpp */
using namespace std;
class Word  
{
  private:
    const char lang; int freq; char* str;
  public:
    Word() : lang('E'), freq(0), str(nullptr) { };
    Word(const char* s, int f = 1, char g = 'E') 
        { str = new char [strlen(s)+1]; strcpy(str, s); }
    void print() const
        { cout << str << " : " << freq << endl; }
};

int main() { Word x("hkust"); }

/*
error: constructor for Word must explicitly initialize the const member 'lang'
-> constants must be initialize (be assigned) once created.
-> default value OR MIL
-> you cannot assign to it after its construction.
*/
