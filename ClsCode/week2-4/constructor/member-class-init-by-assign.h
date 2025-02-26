Word_Pair(const char* x, const char* y) { w1 = x; w2 = y; }

/*
#include <iostream>
#include <cstring>

class Word               File: mil-word.h 
{
    private:
      char lang;
      int freq; 
      char* str;
  
    public:
      Word() : lang('E'), freq(0), str(nullptr) { };
  
       Or, using the braced initialization syntax as follows
         Word() : lang{'E'}, freq{0}, str{nullptr} { };
      
  
      Word(const char* s, int f = 1, char g = 'E') : lang(g), freq(f)
          { str = new char [strlen(s)+1]; strcpy(str, s); }
  
      void print() const { std::cout << str << " : " << freq << std::endl; }
  };
  
  
  class Word_Pair   File: member-class-init-by-mil.h 
  {
    private:
      Word w1; Word w2;
    public:
      Word_Pair(const char* x, const char* y) { w1 = x; w2 = y; }
      void print(void) { w1.print(); w2.print(); }
  };
  
  int main(int argc, char* argv[])
  {
    Word_Pair pair("ahj", "b");
    pair.print();
  
    return 0;
  }

  RESULTS:
    ahj : 1
    b : 1
    -> cpp tries to construct an object of type Word_Pair using char* -> conversion
    -> and then copies the x and y to the member object (w1, w2)
*/