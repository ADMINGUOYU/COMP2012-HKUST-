#include "person.h" /* File: person-test2.cpp */

int main()
{
    Person a("Alan");
    Person b("Brian");
    Person c("Cindy");
    Person d("Debbie");

    for (const Person* p = Person::head; p; p = p->get_next())
        cout << p->get_name() << endl;
    
    return 0;
} // Compile: g++ person.cpp person-test2.cpp
