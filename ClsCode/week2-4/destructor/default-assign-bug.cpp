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

/*
************************************
************Run results*************
************************************
delete: bug
delete: 
free(): double free detected in tcache 2
Aborted (core dumped)

explaination:
object 'bug' is destructed after termination of function Bug;
when performing 'x = bug' only shallow takes place -> the pointer value is copied;
ERROR 1: the original allocated memory (storing "Titanic") becomes garbage;
ERROR 2: after completion of main function, the object 'movie' is destructed -> the destructor tries to delete pointer 'str'(which has already been deleted)
*/