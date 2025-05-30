#include <iostream>     /* File: init-order2.cpp */
using namespace std;

class Address {
  public:
    Address() { cout << "Address's constructor" << endl; }
    ~Address() { cout << "Address's destructor" << endl; }
};

class UPerson { 
  public:
    UPerson() { cout << "UPerson's constructor" << endl; }
    ~UPerson() { cout << "UPerson's destructor" << endl; }
  private: Address address;
};

class Student : public UPerson {
  public:
    Student() { cout << "Student's constructor" << endl; }
    ~Student() { cout << "Student's destructor" << endl; }
};

int main() { Student x; return 0; }

/*
Result:
KEY: go find the most ROOT class's data member -> initialize it first

Address's constructor
UPerson's constructor
Student's constructor

Student's destructor
UPerson's destructor
Address's destructor
*/