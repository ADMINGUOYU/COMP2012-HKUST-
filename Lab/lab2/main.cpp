#include <iostream>
#include "class.h"

using namespace std;

int main() {
    cout << "Creating students..." << endl;
    Student* alice = new Student("Alice");
    Student* bob = new Student("Bob");
    Student* charlie = new Student("Charlie");
    Student* david = new Student("David");

    cout << "\nCreating classes..." << endl;
    Class* comp2012 = new Class("COMP 2012", 2);
    Class* math1014 = new Class("MATH 1014", 3);

    cout << "\nEnrolling students in COMP 2012..." << endl;
    comp2012->enrollStudent(alice);
    comp2012->enrollStudent(bob);

    // Edge Case 1: Trying to enroll a student when the class is full
    cout << "\nAttempting to enroll Charlie in COMP 2012 (should fail)..." << endl;
    comp2012->enrollStudent(charlie);

    cout << "\nEnrolling students in MATH 1014..." << endl;
    math1014->enrollStudent(charlie);
    math1014->enrollStudent(david);

    cout << "\nListing students in COMP 2012:" << endl;
    comp2012->listStudents();

    cout << "\nListing classes for Alice:" << endl;
    alice->listClasses();

    // Edge Case 2: Dropping a student who is not enrolled
    cout << "\nAttempting to drop Charlie from COMP 2012 (should fail)..." << endl;
    comp2012->dropStudent(charlie);

    cout << "\nDropping Bob from COMP 2012..." << endl;
    comp2012->dropStudent(bob);

    cout << "\nListing students in COMP 2012 after dropping Bob:" << endl;
    comp2012->listStudents();

    cout << "\nListing classes for Bob:" << endl;
    bob->listClasses();

    // Edge Case 3: Deleting a student while still enrolled
    cout << "\nDeleting Charlie while enrolled in MATH 1014..." << endl;
    delete charlie;

    cout << "\nListing students in MATH 1014 after deleting Charlie:" << endl;
    math1014->listStudents();  // Should handle the dangling pointer issue

    cout << "\nCleaning up remaining memory..." << endl;
    delete alice;
    delete bob;
    delete david;
    delete comp2012;
    delete math1014;

    cout << "\nProgram execution complete!" << endl;
    return 0;
}
