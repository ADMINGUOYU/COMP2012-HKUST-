// ********************************************* //
// This file is meant for separate testing ONLY! //
// ********************************************* //

#include <iostream>
#include <cstring>      /* File: default-assign-bug.cpp */
// note that <cstring> header is for function strlen()

class Word 
{ 
  private:
    int frequency; char* str; 

  public:
    Word() : frequency(0), str(nullptr) { }
    Word(const char* s, int k = 0): frequency(k) 
	    { str = new char [strlen(s)+1]; strcpy(str, s); }
    ~Word() { std::cout << "delete: " << this->str << std::endl; delete [] str; }
};

void Bug(Word& x) { Word bug("bug", 4); x = bug; }

int main() { Word movie {"Titanic"}; Bug(movie); return 0; }
