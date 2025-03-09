#include <iostream>     /* File: rtti2.cpp */
#include <typeinfo>     // In order to use typeid
using namespace std;
#include "v-student.h"
#include "v-teacher.h"
int main()
{
    char person_type; string name; UPerson* uperson[3];

    for (int j = 0; j < sizeof(uperson)/sizeof(UPerson*); ++j) {
        cout << "Input the uperson type (u/s/t) and his name : ";
        cin >> person_type >> name;
        switch (person_type) {
            case 'u': uperson[j] = new UPerson(name, MAE); break;
            case 's': uperson[j] = new Student(name, CIVL, 4.0); break;
            case 't': uperson[j] = new Teacher(name, CSE, DEAN, "AI"); break;
        }
    }
    cout << boolalpha;
    for (int i = 0; i < sizeof(uperson)/sizeof(UPerson*); ++i) {
        for (int j = 0; j < sizeof(uperson)/sizeof(UPerson*); ++j)
            cout << (typeid(*uperson[i]) == typeid(*uperson[j])) << "\t";
        cout << endl;
    }
} // The example does't destruct the dynamically allocated objects
