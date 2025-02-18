#include "employee.h"
#include <iostream> // for std::cout, std::endl, etc.

using namespace std;

// Getter methods
string Employee::getName() const
{
    // TODO: Return the name
    // Actually this function can be made inline
    return this->name;
}

double Employee::getSalary() const
{
    // TODO: Return the salary
    return this->salary;
}

char Employee::getGender() const
{
    // TODO: Return the gender
    return this->gender; 
}

string Employee::getTitle() const
{
    // TODO: Return the title
    return this->title;
}

// Setter methods
void Employee::setName(const string &newName)
{
    // TODO: Set the name
    // note that the name in the param list is passed by reference

    this->name = newName;   // this performs COPY
    return;
}

void Employee::setSalary(double newSalary)
{
    // TODO: Set the salary
    this->salary = newSalary;
    return;
}

void Employee::setGender(char newGender)
{
    // TODO: Set the gender
    this->gender = newGender;
    return;
}

void Employee::setTitle(const string &newTitle)
{
    // TODO: Set the title
    this->title = newTitle;
    return;
}

// Print method
void Employee::print() const
{
    // TODO: Print in the format:
    // [Name: <name>, Title: <title>, Gender: <gender>, Salary: <salary>]
    std::cout << "["
              << "Name: " << this->name << ", "
              << "Title: " << this->title << ", "
              << "Gender: " << this->gender << ", "
              << "Salary: " << this->salary
              << "]"
              << std::endl;
    return;
}