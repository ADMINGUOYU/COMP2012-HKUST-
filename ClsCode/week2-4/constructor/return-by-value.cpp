#include <iostream>     /* File: return-by-value.cpp */
#include <cstring> 
using namespace std;
class Word
{
  private:
    int frequency; char* str;
    void set(int f, const char* s)
        { frequency = f; str = new char [strlen(s)+1]; strcpy(str, s); }
  public:
    Word(const char* s, int k = 1) { set(k, s); cout << "conversion\n"; }
    Word(const Word& w) { set(w.frequency, w.str); cout << "copy\n"; }
    void print() const { cout << str << " : " << frequency << endl; }
    Word to_upper_case() const 
    {
        Word x(*this);  //copy constructor called
        for (char* p = x.str; *p != '\0'; p++) *p += 'A' - 'a';
        return x;
    }
};
int main()
{
    Word movie {"titanic"};   //conversion constructor called
    movie.print();
    Word song = movie.to_upper_case();  // copy(to song) + copy(to temp object)
    song.print();
}

/*
compiler optimization:
the object meant to be created in line 16 and line 25 is optimized by compiler,
so copy is only done by ONCE and directly to the final destination -> variable 'song'
the copy constructor is called (triggered) at the first time of copy (in this case at line 16)

!! use flag: '-fno-elide-constructors' to disable this feature -> GNU g++
*/
