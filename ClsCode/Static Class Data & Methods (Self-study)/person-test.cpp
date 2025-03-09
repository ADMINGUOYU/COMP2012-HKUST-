#include "person.h" /* File: person-test.cpp */

int main()
{
    new Person("Alan");
    new Person("Brian");
    new Person("Cindy");
    new Person("Debbie");

    for (const Person* p = Person::head; p; p = p->get_next())
        cout << p->get_name() << endl;
    
	// Deleting all the dynamically created Person objects
    for (const Person* p = Person::head; p; p = p->get_next())
        delete p;

    return 0;
} // Compile: g++ person.cpp person-test.cpp
