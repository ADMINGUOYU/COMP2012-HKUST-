#include <iostream>
#include "employee.h"
#include "company.h"

using namespace std;

int main() {
    // Create several employees
    Employee e1, e2, e3, e4;
    e1.setName("Alice");
    e1.setSalary(30000);
    e1.setGender('F');
    e1.setTitle("Engineer");

    e2.setName("Bob");
    e2.setSalary(32000);
    e2.setGender('M');
    e2.setTitle("Engineer");

    e3.setName("Cindy");
    e3.setSalary(40000);
    e3.setGender('F');
    e3.setTitle("Manager");

    e4.setName("Dave");
    e4.setSalary(35000);
    e4.setGender('M');
    e4.setTitle("Engineer");

    // Initialize a company
    Company myCompany;
    myCompany.init();

    // Demonstration of adding employees
    cout << "Adding employee Alice..." << endl;
    myCompany.addEmployee(&e1);

    cout << "Adding employee Bob..." << endl;
    myCompany.addEmployee(&e2);

    cout << "Adding employee Cindy..." << endl;
    myCompany.addEmployee(&e3);

    cout << "Adding employee Dave..." << endl;
    myCompany.addEmployee(&e4);

    cout << "\nAdding employee Bob again..." << endl;
    myCompany.addEmployee(&e2);

    // Firing a non-existent employee
    cout << "\nFiring Frank..." << endl;
    myCompany.fireEmployee("Frank");

    // Print current state
    cout << endl;
    myCompany.print();
    cout << endl;

    // Fire an existing employee
    cout << "Firing Bob..." << endl;
    myCompany.fireEmployee("Bob");

    // Promote a non-existent employee
    cout << "\nPromoting Bob to Senior Engineer..." << endl;
    myCompany.promoteEmployee("Bob", "Senior Engineer");

    // Promote an existing employee
    cout << "\nPromoting Cindy to Senior Engineer..." << endl;
    myCompany.promoteEmployee("Cindy", "Senior Engineer");

    // Adjusting salary for an existing employee
    cout << "\nAdjusting salary of Alice by -500..." << endl;
    myCompany.adjustSalary("Alice", -500);

    // Adjusting salary for a non-existent employee
    cout << "\nAdjusting salary of Bob by 1000..." << endl;
    myCompany.adjustSalary("Bob", 1000);

    // Final state
    cout << endl;
    myCompany.print();

    return 0;
}