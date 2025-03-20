#include "Factory.h"

Factory::Factory(int cap) : capacity(cap), count(0) {
    vehicles = new Vehicle*[capacity];
}

Factory::~Factory() {
    for (int i = 0; i < count; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;
}

void Factory::addVehicle(Vehicle* vehicle) {
    // To do3: Implement the addVehicle function
    if (this->count < this->capacity) {
        // Check if array is full
        // Add vehicle to array
        this->vehicles[this->count++] = vehicle;
    } else {

        cout << "Factory is full, cannot add more vehicles!" << endl;
    }
    return;
}

void Factory::listAllVehicles() const 
{
// To do3: Implement the listAllVehicles function
    for (int i = 0; i < this->count; i++)
        this->vehicles[i]->displayInfo();
    return;
}

void Factory::listCombustionVehicles() const 
{
// To do3: Implement the listCombustionVehicles function
// here, we have to use type checking
    for (int i = 0; i < this->count; i++)
    {
        if (typeid(CombustionVehicle) == typeid((*this->vehicles[i])))
            this->vehicles[i]->displayInfo();
    }
    return;
}

void Factory::listElectricVehicles() const 
{
// To do3: Implement the listElectricVehicles function
// here, we have to use type checking
    for (int i = 0; i < this->count; i++)
    {
        if (typeid(ElectricVehicle) == typeid((*this->vehicles[i])))
            this->vehicles[i]->displayInfo();
    }
    return;
}

double Factory::calculateTotalCombustionCost() const {
// Todo4: Implement the calculateTotalConsumption function
    double totalCost = 0.0;
    for (int i = 0; i < this->count; i++)
    {
        if (typeid(CombustionVehicle) == typeid((*this->vehicles[i])))
            totalCost += this->vehicles[i]->calculateCost();
    }
    return totalCost;
}

double Factory::calculateTotalElectricCost() const {
// Todo3: Implement the calculateTotalElectricCost function
    double totalCost = 0.0;
    for (int i = 0; i < this->count; i++)
    {
        if (typeid(ElectricVehicle) == typeid((*this->vehicles[i])))
            totalCost += this->vehicles[i]->calculateCost();
    }
    return totalCost;
}

double Factory::calculateTotalCost() const {
// Todo3: Implement the calculateTotalCost function
    double totalCost = 0.0;
    for (int i = 0; i < this->count; i++)
        totalCost += this->vehicles[i]->calculateCost();
    return totalCost;
} 