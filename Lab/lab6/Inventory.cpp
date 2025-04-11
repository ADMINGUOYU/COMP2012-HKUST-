#include "Inventory.h"
#include <algorithm>

// Default constructor
Inventory::Inventory() : items(nullptr), size(0) {}

// Copy constructor
Inventory::Inventory(const Inventory& other)
    : items(nullptr), size(0)
{
    if (other.size > 0) {
        size = other.size;
        items = new Item<int>[size];
        for (int i = 0; i < size; i++) {
            items[i] = other.items[i];
        }
    }
}

// Destructor
Inventory::~Inventory() {
    delete[] items;
}

// Task 5: Implement operator=
/*
Implement deep copying of the dynamic items array.
Notice: Handle self-assignment properly (check if (this == &other)).
*/
Inventory& Inventory::operator=(const Inventory& other) {
    // TODO: Task 5
    if (this == &other) return (*this); // self assignment, return this directly
    // now performs copy
    delete[] this->items;
    this->items = nullptr;
    this->size = 0;

    if (other.size > 0) {
        size = other.size;
        items = new Item<int>[size];
        for (int i = 0; i < size; i++) {
            items[i] = other.items[i];
        }
    }
    return (*this);
}

// Task 6: Implement operator+
/*
Merge two inventories into a single Inventory that holds all items.
Notice: Allocate space appropriately and copy items from both sides.
*/
Inventory operator+(const Inventory& lhs, const Inventory& rhs) {
    // TODO: Task 6
    Inventory merged {};
    // I know you can call 'addItem' for each item
    // But I do not like this approach
    merged.size = lhs.size + rhs.size;
    merged.items = new Item<int>[merged.size];
    int i = 0;  // used for index counter
    for (int j = 0; j < lhs.size; j++) merged.items[i++] = lhs.items[j];
    for (int j = 0; j < rhs.size; j++) merged.items[i++] = rhs.items[j];
    return merged;

    /*
    Not sure which version
    merged.size = (lhs.size > rhs.size) ? lhs.size : rhs.size;
    merged.items = new Item<int>[merged.size];
    for (int i = 0; i < merged.size; i++)
    {
        if (i >= lhs.size) merged.items[i] = rhs.items[i];
        else if (i >= rhs.size) merged.items[i] = lhs.items[i];
        else merged.items[i] = lhs.items[i] + rhs.items[i];
    }
    */
}

// Add an item to the end of the inventory
void Inventory::addItem(const Item<int>& newItem) {
    Item<int>* temp = new Item<int>[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = items[i];
    }
    temp[size] = newItem;
    delete[] items;
    items = temp;
    size++;
}

// Printing the inventory
std::ostream& operator<<(std::ostream& os, const Inventory& inv) {
    os << "[";
    for (int i = 0; i < inv.size; i++) {
        os << inv.items[i];
        if (i < inv.size - 1) os << ", ";
    }
    os << "]";
    return os;
}