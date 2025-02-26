#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "class.h"

using namespace std;

/*
 * Interactive program to manage student-class registrations.
 * Commands recognized (case-sensitive):
 *   1) createStudent <name>
 *   2) createClass <className> <capacity>
 *   3) enroll <studentName> <className>
 *   4) drop <studentName> <className>
 *   5) listStudents <className>
 *   6) listClasses <studentName>
 *   7) exit
 *
 */

int main() {
    vector<Student*> students;
    vector<Class*> classes;

    string line;
    while (true) {
        if (!getline(cin, line)) {
            break;
        }
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "exit") {
            break;
        } else if (command == "createStudent") {
            string name;
            ss >> name;
            students.push_back(new Student(name.c_str()));
            // cout << "Student " << name << " created." << endl;
        } else if (command == "createClass") {
            string className;
            int capacity;
            ss >> className >> capacity;
            classes.push_back(new Class(className.c_str(), capacity));
            // cout << "Class " << className << " with capacity " << capacity << " created." << endl;
        } else if (command == "enroll") {
            string studentName, className;
            ss >> studentName >> className;
            
            Student* student = nullptr;
            Class* classObj = nullptr;
            
            for (auto* s : students) {
                if (s->getName() == studentName) {
                    student = s;
                    break;
                }
            }
            for (auto* c : classes) {
                if (c->getName() == className) {
                    classObj = c;
                    break;
                }
            }
            
            if (student && classObj) {
                classObj->enrollStudent(student);
            } else {
                cout << "Invalid student or class name." << endl;
            }
        } else if (command == "drop") {
            string studentName, className;
            ss >> studentName >> className;
            
            Student* student = nullptr;
            Class* classObj = nullptr;
            
            for (auto* s : students) {
                if (s->getName() == studentName) {
                    student = s;
                    break;
                }
            }
            for (auto* c : classes) {
                if (c->getName() == className) {
                    classObj = c;
                    break;
                }
            }
            
            if (student && classObj) {
                classObj->dropStudent(student);
            } else {
                cout << "Invalid student or class name." << endl;
            }
        } else if (command == "listStudents") {
            string className;
            ss >> className;
            
            for (auto* c : classes) {
                if (c->getName() == className) {
                    c->listStudents();
                    break;
                }
            }
        } else if (command == "listClasses") {
            string studentName;
            ss >> studentName;
            
            for (auto* s : students) {
                if (s->getName() == studentName) {
                    s->listClasses();
                    break;
                }
            }
        } else {
            cout << "Unknown command: " << command << endl;
        }
    }

    // Cleanup allocated memory
    for (auto* s : students) delete s;
    for (auto* c : classes) delete c;
    
    return 0;
}
