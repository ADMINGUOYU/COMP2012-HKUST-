#ifndef COMPANY_H
#define COMPANY_H

#include "employee.h"
#include <string>

const int COMPANY_MAX_SIZE = 3;

class Company {
public:
    // Initialize data members (e.g., currSize = 0, employees[i] = nullptr)
    void init();

    // Add (hire) an Employee if there's space and not already in the array (by name).
    // Print messages as required:
    //    - "Employee <name> already exists in the company" if duplicate
    //    - "Company is full" if no space
    //    - "Employee <name> is hired" if success
    void addEmployee(Employee *emp);

    // Remove (fire) an Employee by name.
    // Print messages as required:
    //    - "Employee <name> is not found in the company" if not found
    //    - "Employee <name> is fired" if success
    void fireEmployee(const std::string& empName);

    // Check if the company has an employee with the given name.
    bool hasEmployee(const std::string& empName) const;

    // Promote an Employee (change title) by name.
    // Print messages:
    //    - "Employee <name> is not found in the company" if not found
    //    - "Employee <name> is promoted to <newTitle>" if success
    void promoteEmployee(const std::string& empName, const std::string& newTitle);

    // Adjust an Employee's salary by a given amount.
    // Print messages:
    //    - "Employee <name> is not found in the company" if not found
    //    - "Employee <name>'s salary is changed by <amount>" if success
    void adjustSalary(const std::string& empName, double amount);

    // Print a summary of the company:
    // e.g. "Company with X employees:", then list each employee via Employee::print().
    void print() const;

private:
    // Helper function to find the employee by name.
    // Returns the index if found; otherwise, returns -1.
    int findEmployee(const std::string& empName) const;

    int currSize; // how many employees are currently in the company
    Employee *employees[COMPANY_MAX_SIZE];
};

#endif
