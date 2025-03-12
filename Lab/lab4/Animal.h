#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include "Exhibit.h"
using namespace std;

class Animal {
    private:
        string name;
        int age;
        Exhibit* exhibit;    
    
    public:
        Animal(const string& name, int age);
        
        string get_name() const;
        int get_age() const;
        Exhibit* get_exhibit() const;
        void set_exhibit(Exhibit* exhibit);
        void print_info() const;
};

#endif