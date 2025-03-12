#include <iostream>
#include "IndoorExhibit.h"

// TODO 2.1: Implement the constructor using member initializer list
IndoorExhibit::IndoorExhibit(const string& name, int area_code, const string& climate_type)
 
    {
        set_type("indoor"); //Set the type to "indoor"
    }


// TODO 2.2: Implement get_climate_type()
string IndoorExhibit::get_climate_type() const {

} 

void IndoorExhibit::print_info() const {
    cout << "Indoor exhibit " << get_name() << " (" << climate_type << " environment)" << endl;
}