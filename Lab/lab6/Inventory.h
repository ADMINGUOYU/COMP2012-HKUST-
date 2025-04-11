#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <iostream>

class Inventory {
private:
    Item<int>* items;  // dynamic array of Item<int>
    int size;

public:
    // Constructors & Destructor
    Inventory();                     
    Inventory(const Inventory& other); 
    ~Inventory();
    
    void addItem(const Item<int>& newItem);

    // Assignment Inventory by operator=
    Inventory& operator=(const Inventory& other);

    // Merge two Inventories by operator+
    friend Inventory operator+(const Inventory& lhs, const Inventory& rhs);

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Inventory& inv);
};

#endif