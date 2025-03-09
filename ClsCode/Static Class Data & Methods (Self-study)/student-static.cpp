#include "student-static.h" /* File: student-static.cpp */

// Define AND initialize static data globally
string Student::memory[MAX_MEM] { };
int Student::amount_of_memory {0};

void Student::do_exam()
{
    if (amount_of_memory == 0)  // Haven't studied anything!
        cout << name << ": "<< "Huh???" << endl;
    else 
    {
        for (int k = 0; k < amount_of_memory; ++k)
    	    cout << name << ": " << memory[k] << endl;
    }

    cout << endl;
}
