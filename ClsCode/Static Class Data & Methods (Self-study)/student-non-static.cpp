#include "student-non-static.h" /* File: student-non-static.cpp */

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