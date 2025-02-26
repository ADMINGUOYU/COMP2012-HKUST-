#include <iostream>     /* File: rtti.cpp */
#include <typeinfo>     // In order to use typeid
using namespace std;
#include "v-student.h"
#include "v-teacher.h"
int main()
{
    char person_type; string name; UPerson* uperson[3];

    for (int j = 0; j < sizeof(uperson)/sizeof(UPerson*); ++j)
    {
        cout << "Input the uperson type (u/s/t) and his name : ";
        cin >> person_type >> name;
        switch (person_type)
        {
            case 'u': uperson[j] = new UPerson(name, MAE); break;
            case 's': uperson[j] = new Student(name, CIVL, 4.0); break;
            case 't': uperson[j] = new Teacher(name, CSE, DEAN, "AI"); break;
        }
    }

    for (int j = 0; j < sizeof(uperson)/sizeof(UPerson*); ++j)
        cout << "The uperson #" << j << " is a "
             << typeid(*uperson[j]).name() << endl; // RTTI
} // The example does't destruct the dynamically allocated objects
