#include <iostream>     /* File: student-static.h */
#include <string>
using namespace std;
const int MAX_MEM {100};

class Student
{
  private:
    string name;                   // Student's name 
    static string memory[MAX_MEM]; // Students share their memories
    static int amount_of_memory;

  public:
    Student(string s) : name(s) { }
    void do_exam();

    void memorize(string txt) 
    { 
        if (amount_of_memory >= MAX_MEM)
            cerr << name << " can't memorize anything anymore!\n" << endl;
        else
            memory[amount_of_memory++] = txt; 
    }
};
