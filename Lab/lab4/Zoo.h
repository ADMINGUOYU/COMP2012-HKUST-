#ifndef ZOO_H
#define ZOO_H
#include <string>
#include "Exhibit.h"
#include "Animal.h"
#include "IndoorExhibit.h"
#include "OutdoorExhibit.h"

using namespace std;

class Zoo {
    private:
        Animal** animals;
        int max_animals;
        int num_animals;
    public:
        Zoo(int max_animals);
        ~Zoo();
        bool add_animal_to_indoor(Animal* animal, IndoorExhibit* exhibit);
        bool add_animal_to_outdoor(Animal* animal, OutdoorExhibit* exhibit);
        bool remove_animal(const string& name);
        void print_all_animals() const;
};

#endif