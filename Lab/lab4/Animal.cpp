#include <iostream>
#include "Animal.h"
#include "IndoorExhibit.h"
#include "OutdoorExhibit.h"


Animal::Animal(const string& name, int age) {
    this->name = name;
    this->age = age;
    this->exhibit = nullptr;
}


string Animal::get_name() const {
    return name;
}

int Animal::get_age() const {
    return age;
}

Exhibit* Animal::get_exhibit() const {
    return exhibit;
}

void Animal::set_exhibit(Exhibit* exhibit) {
    this->exhibit = exhibit;
}


void Animal::print_info() const {
    cout << name << " (age " << age << ") is created."  << endl;;
}

