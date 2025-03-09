#include "person.h"     /* File: person.cpp */

// Definition and initialization of static class member
Person* Person::head = 0; // Empty linked list
 
// New Person is always added to the front
Person::Person(string s) : name(s), next(head) { head = this; }

Person::Person(const Person &p)
        : name(p.name), next(head) { head = this; }

Person::~Person()
{
	cout << "deleting " << name << endl;

    if (this == head) { head = next; return; }

    for (Person* p = head; p; p = p->next) 
        if (p->next == this) { p->next = next; return; }
}
