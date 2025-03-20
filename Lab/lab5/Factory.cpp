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
    if () {
        // Check if array is full
        // Add vehicle to array
    } else {

        cout << "Factory is full, cannot add more vehicles!" << endl;
    }
}

void Factory::listAllVehicles() const {
// To do3: Implement the listAllVehicles function
}

void Factory::listCombustionVehicles() const {
// To do3: Implement the listCombustionVehicles function
}

void Factory::listElectricVehicles() const {
// To do3: Implement the listElectricVehicles function
}

double Factory::calculateTotalCombustionCost() const {
// Todo4: Implement the calculateTotalConsumption function
    return totalCost;
}

double Factory::calculateTotalElectricCost() const {
// Todo3: Implement the calculateTotalElectricCost function
    return totalCost;
}

double Factory::calculateTotalCost() const {
// Todo3: Implement the calculateTotalCost function
    return totalCost;
} 