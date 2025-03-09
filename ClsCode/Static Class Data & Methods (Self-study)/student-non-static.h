#include <iostream>     /* File: student-non-static.h */
#include <string>
using namespace std;
const int MAX_MEM {100};

class Student
{
  private:
    string name;            // Student's name 
    string memory[MAX_MEM]; // Each student has his own memory
    int amount_of_memory = 0;

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
