#include "company.h"
#include <iostream>
using namespace std;

void Company::init() 
{
    // TODO
    // Initialize data members (e.g., currSize = 0, employees[i] = nullptr)
    this->currSize = 0;
    for(int i = 0; i < COMPANY_MAX_SIZE; i++)
    {
        this->employees[i] = nullptr;
    }
    return;
}

void Company::addEmployee(Employee* emp)
{
    // Check if the employee already exists by name
    if (hasEmployee(emp->getName())) {
        cout << "Employee " << emp->getName() << " already exists in the company" << endl;
        return;
    }

    // Check if company is full
    if (currSize == COMPANY_MAX_SIZE) {
        cout << "Company is full" << endl;
        return;
    }

    // Otherwise, add the employee
    employees[currSize] = emp;
    currSize++;
    cout << "Employee " << emp->getName() << " is hired" << endl;
}

int Company::findEmployee(const string& empName) const
{
    // TODO
    // Return the index of the Employee whose name is empName in the employees array. 
    // If the employee is not found, return -1.

    int index = 0;  // not necessary, just to try out the new feature
    for (Employee* ptr : this->employees)
    // using the new C++ 11 feature
    {
        if ((ptr != nullptr) && (*ptr).getName() == empName) { return index; }
        index++;
    }

    // if not found return -1
    return -1;
}

bool Company::hasEmployee(const string& empName) const
{
    return findEmployee(empName) != -1;
}

void Company::fireEmployee(const string& empName)
{
    // TODO
    /*
    If an Employee with empName is found, remove it and shift the array so there are no gaps.
    Print "Employee <name> is fired" if successful.
    If not found, print "Employee <name> is not found in the company".
    */

    int index {-1}; //try using the new initialization braces
    if (-1 != (index = this->findEmployee(empName)))
    {
        // found -> we don't need to take care of the memory -> just delete the pointer
        this->employees[index] = nullptr;
        for (int i = index; i < COMPANY_MAX_SIZE - 1; i++)
        {
            this->employees[i] = this->employees[i + 1];
        }
        this->employees[COMPANY_MAX_SIZE - 1] = nullptr;
        this->currSize--;
        std::cout << "Employee " << empName << " is fired" << std::endl;
    }
    else
    {
        // not found
        std::cout << "Employee " << empName << " is not found in the company" << std::endl;
    }
    return;
}

void Company::promoteEmployee(const string& empName, const string& newTitle)
{
    // TODO
    /*
    If found, call that Employee’s setTitle(newTitle), then print "Employee <name> is promoted to <newTitle>".
    If not found, print "Employee <name> is not found in the company".
    */

   int index {-1}; //try using the new initialization braces
   if (-1 != (index = this->findEmployee(empName)))
   {
       // found -> we don't need to take care of the memory -> just delete the pointer
       this->employees[index]->setTitle(newTitle);
       std::cout << "Employee " << empName << " is promoted to " << this->employees[index]->getTitle() << std::endl;
   }
   else
   {
       // not found
       std::cout << "Employee " << empName << " is not found in the company" << std::endl;
   }
    return;
}

void Company::adjustSalary(const string& empName, double amount)
{
    // Find the employee to adjust the salary.
    int index = findEmployee(empName);
    if (index == -1) {
        cout << "Employee " << empName << " is not found in the company" << endl;
        return;
    }

    // Adjust the salary.
    double updatedSalary = employees[index]->getSalary() + amount;
    employees[index]->setSalary(updatedSalary);
    cout << "Employee " << empName << "'s salary is changed by " << amount << endl;
}

void Company::print() const
{
    // TODO
    /*
    Print "Company with X employees:", where X is currSize.
    Then call Employee::print() on each stored Employee pointer (in the order they appear in employees).
    Notice that you should print four spaces before each employee's information.
    */
    std::cout << "Company with " << this->currSize <<" employees:" << std::endl;
    for (int i = 0; i < this->currSize; i++)
    {
        std::cout << "    ";
        this->employees[i]->print();
    }
    return;
}
