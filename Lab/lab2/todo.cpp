#include "class.h"
#include <iostream>
#include <cstring>

using namespace std;

// Student constructor
/*
Implement the Student constructor to initialize the student's name and enrolled classes.
    Allocate memory for name using strlen and strcpy.
    Initialize classes as a dynamic array with an initial capacity of 2.
    Set classCount to 0 and classCapacity to 2.
    Print a message: "Student: " +name+" initialized!"
*/
Student::Student(const char* name)
    :
    name(nullptr),
    classes(nullptr),
    classCount(),
    classCapacity()
{
    this->name = new char[strlen(name) + 1];    // +1 for null character
    strcpy(this->name, name);                   // copy the string

    this->classes = new Class*[2];              // init dynamic array (array of pointers)
    this->classCount = 0;                       // init classCount = 0
    this->classCapacity = 2;                    // init classCapacity = 2

    std::cout << "Student: " << this->name << " initialized!" << std::endl;

    return;
}

// Student destructor
/*
Implement the Student destructor to properly release allocated resources.
    Ensure the student is removed from all enrolled classes before deletion.
        Create a temporary array to hold the classes to be dropped.
        Collect all the classes the student is enrolled in before deleting the student.
    Drop the student from each class safely.
    Free memory for name.
    Free memory for classes.
    Print a message: "Student: " + name + " destroyed!".
*/
Student::~Student() 
{
    // according to 'dropClass' no nullptr is added -> so the only thing to keep track of is classCount
    int num_of_class_to_delete = this->classCount - 1;      // remember to record the total number -> as dropClass() called in dropStudent() will decrease the number of this->classCount
    for (int i = 0; i <= num_of_class_to_delete; i++)
    {
        this->classes[0]->dropStudent(this);    // drop this student first
        //this->dropClass(this->classes[0]);      // drop this class
    }

    delete [] this->classes;    // free memory -> classes
    this->classes = nullptr;
    this->classCapacity = 0;

    std::cout << "Student: " << this->name << " destroyed!" << std::endl;
    delete [] this->name;   // free memory -> name
    this->name = nullptr;

    return;
}

// Class constructor
/*
Implement the Class constructor to initialize the class name and student list.
    Allocate memory for name using strlen and strcpy.
    Initialize students as a dynamic array with a size equal to capacity.
    Set studentCount to 0.
    Print a message: "Class: "+name+" created with capacity "+capacity+"."
*/
Class::Class(const char* name, int capacity) 
    :
    name(nullptr),
    students(nullptr),
    studentCount(0),
    capacity(capacity)
{
    this->name = new char[strlen(name) + 1];    // +1 for null character
    strcpy(this->name, name);                   // copy the string
    
    this->students = new Student*[this->capacity];
    std::cout << "Class: " << this->name << " created with capacity " << this->capacity << "." << std::endl;
    
    return;
}

// Class destructor
/*
Implement the Class destructor to properly release allocated resources.
    Free memory for name .
    Free memory for students .
    Print a message: "Class: "+name+" destroyed."
    There is no need to drop students from the class in the destructor because students will drop all classes in their destructor.
*/
Class::~Class() 
{
    delete [] this->students;
    this->students = nullptr;

    std::cout << "Class: " << this->name << " destroyed." << std::endl;
    delete [] this->name;
    this->name = nullptr;
    return;
}



// Enroll a student in the class
/*
Implement the Class::enrollStudent function to add a student to the class.
    Check if the class is full. If full, print an error message:"Class "+name+" is full. Cannot enroll student!" and return false.
    Add the student to the students array.
    Call enrollInClass on the student.
    Print a message: "Student "+student's name+" enrolled in class " +name+"."
*/
bool Class::enrollStudent(Student* student) {
    if (this->studentCount >= this->capacity)
    {
        std::cout << "Class " << this->name << " is full. Cannot enroll student!" << std::endl;
        return false;
    }

    this->students[this->studentCount] = student;
    this->studentCount++;

    student->enrollInClass(this);
    std::cout << "Student " << student->getName() << " enrolled in class " << this->name << "." << std::endl;
    
    return true;
}

// Drop a student from the class
/*
Implement the Class::dropStudent function to remove a student from the class.
    Find the student in the students array.
    Shift elements left to remove the student from the array.
    Clear the last entry in the array.
    Call dropClass on the student.
    Print a message: "Student " +student's name+" dropped from class "+name+"."
    If the student is not found, print an error message: "Student "+student's name+" is not in class "+name+"."
*/
bool Class::dropStudent(Student* student) {
    for (int i = 0; i < this->studentCount; ++i) {
        if (this->students[i] == student) {
            for (int j = i; j < this->studentCount - 1; ++j) {
                this->students[j] = this->students[j + 1];
            }
            this->students[this->studentCount - 1] = nullptr;
            --this->studentCount;

            student->dropClass(this);
            std::cout << "Student " << student->getName() << " dropped from class " << this->name << "." << std::endl;
            return true;
        }
    }
    std::cout << "Student " << student->getName() << " is not in class " << this->name << "." << std::endl;
    return false;
}