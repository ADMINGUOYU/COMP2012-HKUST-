#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
public:
    // Getter methods
    string getName() const;
    double getSalary() const;
    char getGender() const;
    string getTitle() const;

    // Setter methods
    void setName(const string &newName);
    void setSalary(double newSalary);
    void setGender(char newGender);
    void setTitle(const string &newTitle);

    // Print method
    void print() const;

private:
    string name;   // e.g., "Alice"
    double salary; // e.g., 30000
    char gender;   // 'M' or 'F'
    string title;  // e.g. "Engineer", "Senior Engineer", "Manager"
};

#endif