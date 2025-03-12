#include <iostream>
#include "Zoo.h"
#include "Animal.h"
#include "Exhibit.h"
#include "IndoorExhibit.h"   
#include "OutdoorExhibit.h"  
using namespace std;

/*
There are several classes involved in this lab: 
Animal, Exhibit, IndoorExhibit, OutdoorExhibit, and Zoo.

Animal: Represents an animal in the zoo, with data members like 
        name, age and exhibit. 
        Before adding the animal into the zoo, the "exhibit" is empty.

Exhibit: The base class for different types of exhibits, 
        containing common data members like name and area code.

IndoorExhibit and OutdoorExhibit: Derived from Exhibit, 
        representing specific types of exhibits with additional data members like 
        climate type or area.

Zoo: Manages the animals and exhibits, providing functionalities to 
        add, remove, and list animals.
*/

int main() {
    cout << "=== Creating Zoo ===" << endl;
    Zoo zoo(3);  
    
    cout << "\n=== Testing Empty Zoo ===" << endl;
    zoo.print_all_animals();  
    
    cout << "\n=== Creating Animals ===" << endl;
    Animal tiger("Tiger", 5);
    Animal penguin("Penguin", 2);
    Animal elephant("Elephant", 8);
    Animal lion("Lion", 6);

    tiger.print_info();
    penguin.print_info();
    elephant.print_info();
    lion.print_info();
    
    
    cout << "\n=== Testing Animal Addition ===" << endl;
    IndoorExhibit* tropical = new IndoorExhibit("Tropical House", 101, "warm and humid");
    OutdoorExhibit* arctic = new OutdoorExhibit("Arctic Zone", 201, 3000.0);
    
    cout << "\n--- Adding animals within capacity ---" << endl;
    zoo.add_animal_to_indoor(&tiger, tropical);    
    zoo.add_animal_to_outdoor(&penguin, arctic);    
    zoo.add_animal_to_indoor(&elephant, tropical);
    zoo.print_all_animals();

    cout << "\n--- Testing capacity limit ---" << endl;
    zoo.add_animal_to_outdoor(&lion, arctic);       // Fail
    
    cout << "\n=== Testing Animal Removal ===" << endl;
    zoo.remove_animal("Tiger");          
    zoo.remove_animal("Giraffe");        // Fail
    zoo.print_all_animals();
    
    cout << "\n=== Testing Addition After Removal ===" << endl;

    zoo.print_all_animals();
    
    
    delete tropical;
    delete arctic;
    
    return 0;
}