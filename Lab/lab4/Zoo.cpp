#include "Zoo.h"
#include "Animal.h"
#include "Exhibit.h"
#include "IndoorExhibit.h"
#include "OutdoorExhibit.h"
#include <iostream>
using namespace std;

// TODO 4.1: complete the constructor of Zoo
// Initialize the zoo with the specified maximum number of animals
Zoo::Zoo(int max_animals) {
   
}

// TODO 4.2: complete the destructor of Zoo
// Clean up any dynamically allocated memory if necessary
Zoo::~Zoo() {
   
}

// TODO 4.3: complete Zoo::add_to_indoor() and Zoo::add_to_outdoor()
// Add an animal to the zoo if there is space available

bool Zoo::add_animal_to_indoor(Animal* animal, IndoorExhibit* exhibit) {
   
    cout << "Zoo is full. Cannot add more animals." << endl;
      
  
  
    cout << "Added animal " << animal->get_name() 
         << " to indoor exhibit " << animal->get_exhibit()->get_name()
         << " (" << exhibit->get_climate_type() << " environment)" << endl;
    
}

bool Zoo::add_animal_to_outdoor(Animal* animal, OutdoorExhibit* exhibit) {

    cout << "Zoo is full. Cannot add more animals." << endl;
    

    cout << "Added animal " << animal->get_name() 
         << " to outdoor exhibit " << animal->get_exhibit()->get_name()
         << " (area: " << exhibit->get_area() << " square meters)" << endl;
    
}


// TODO 4.4: complete Zoo::remove_animal()
// Remove an animal from the zoo by name
bool Zoo::remove_animal(const string& name) {
   
    
    cout << "Removed animal: " << name << endl;
   
    
    cout << "Animal " << name << " not found in the zoo." << endl;
   
}

void Zoo::print_all_animals() const {
    if (num_animals == 0) {
        cout << "The zoo currently has no animals." << endl;
        return;
    }
    
    cout << "Current animals in the zoo:" << endl;
    for (int i = 0; i < num_animals; i++) {
        cout << animals[i]->get_name() << ", ";  
    }
    cout << endl;
}

