#ifndef CLASS_H
#define CLASS_H

class Class;

class Student {
private:
    char* name;         // Student name
    Class** classes;    // List of classes the student is enrolled in
    int classCount;     // Number of classes
    int classCapacity;  // Capacity of the class list

public:
    // Constructor
    Student(const char* name); // TODO1: Implement in todo.cpp

    // Destructor
    ~Student(); //TODO2: Implement in todo.cpp

    // Get the student's name 
    const char* getName() const; // Provided

    // Enroll in a class
    void enrollInClass(Class* classObj); // Provided

    // Drop a class
    void dropClass(Class* classObj); // Provided

    // List all enrolled classes
    void listClasses() const; // Provided
};

class Class {
private:
    char* name;         // Class name
    Student** students; // List of enrolled students
    int studentCount;   // Number of students
    int capacity;       // Maximum capacity of the class

public:
    // Constructor
    Class(const char* name, int capacity); // TODO3: Implement in todo.cpp

    // Destructor
    ~Class(); // TODO4: Implement in todo.cpp

    // Get the class name
    const char* getName() const; // Provided

    // Enroll a student
    bool enrollStudent(Student* student); // TODO5: Implement in todo.cpp

    // Drop a student
    bool dropStudent(Student* student); // TODO6: Implement in todo.cpp
 
    // List all students in the class
    void listStudents() const; // Provided
};

#endif // CLASS_H
