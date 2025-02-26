#include "class.h"
#include <iostream>
#include <cstring>

using namespace std;

// ========== Class Implementation ==========



// Get class name
const char* Class::getName() const {
    return name;
}




// List all students in the class
void Class::listStudents() const {
    if (studentCount == 0) {
        cout << "No students enrolled in class " << name << "." << endl;
        return;
    }

    cout << "Students in class " << name << ":" << endl;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i] != nullptr) { // Check if student is still valid
            cout << "- " << students[i]->getName() << endl;
        }
    }
}


// ========== Student Implementation ==========




// Get student name
const char* Student::getName() const {
    return name;
}

// Enroll student in a class
void Student::enrollInClass(Class* classObj) {
    if (classCount >= classCapacity) {
        // Expand dynamic array
        classCapacity *= 2;
        Class** newClasses = new Class*[classCapacity];
        for (int i = 0; i < classCount; ++i) {
            newClasses[i] = classes[i];
        }
        delete[] classes;
        classes = newClasses;
    }

    classes[classCount++] = classObj;
}

// Drop student from a class
void Student::dropClass(Class* classObj) {
    for (int i = 0; i < classCount; ++i) {
        if (classes[i] == classObj) {
            for (int j = i; j < classCount - 1; ++j) {
                classes[j] = classes[j + 1];
            }
            --classCount;
            return;
        }
    }
}

// List all classes the student is enrolled in
void Student::listClasses() const {
    if (classCount == 0) {
        cout << "Student: " << name << " is not enrolled in any classes." << endl;
        return;
    }

    cout << "Classes for student " << name << ":" << endl;
    for (int i = 0; i < classCount; ++i) {
        cout << "- " << classes[i]->getName() << endl;
    }
}

