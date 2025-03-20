#ifndef FACTORY_H
#define FACTORY_H

#include "Vehicle.h"
#include <typeinfo>

class Factory {
private:
    Vehicle** vehicles;   // Dynamic array of pointers to Vehicle objects
    int capacity;        // Capacity of the array
    int count;            // Current number of vehicles

public:
    Factory(int cap);
    ~Factory();

    void addVehicle(Vehicle* vehicle);
    void listAllVehicles() const;
    void listCombustionVehicles() const;  
    void listElectricVehicles() const;   
    double calculateTotalCombustionCost() const;  
    double calculateTotalElectricCost() const;    
    double calculateTotalCost() const;
};

#endif // FACTORY_H 