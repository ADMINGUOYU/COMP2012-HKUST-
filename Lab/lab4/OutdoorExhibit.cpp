#include <iostream>
#include "OutdoorExhibit.h"

// TODO 3.1: Implement the constructor using member initializer list
OutdoorExhibit::OutdoorExhibit(const string& name, int area_code, double area)
    :
    Exhibit(name, area_code),
    area(area)
{
    set_type("outdoor"); //Set the type to "outdoor"
    return;
}

// TODO 3.2: Implement get_area()
double OutdoorExhibit::get_area() const 
{
    return (this->area);
}

void OutdoorExhibit::print_info() const {
    cout << "Outdoor exhibit " << get_name() << " (area: " << area << " square meters)" << endl;
}