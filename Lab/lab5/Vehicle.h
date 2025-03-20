#ifndef VEHICLE_H
#define VEHICLE_H


#include <string>
#include <iostream>




using namespace std;

class Vehicle {
protected:
    string model;
    double price;
    int yearOfProduction;
public:
    Vehicle(const string& model, double price, int yearOfProduction);
    virtual void displayInfo() const = 0; 
    virtual double calculateCost() const { return price; }
    virtual ~Vehicle() {}
};

class CombustionVehicle : public Vehicle {
private:
    double fuelConsumption;  // Fuel consumption per 100 kilometers (liters)
    int emissionLevel;       // Emission level
public:
    CombustionVehicle(const string& model, double price, int yearOfProduction, 
                      double fuelConsumption, int emissionLevel);
    double getFuelConsumption() const { return fuelConsumption; }
    int getEmissionLevel() const { return emissionLevel; }
    virtual void displayInfo() const override;
    virtual double calculateCost() const override; // Consider fuel costs
};

class ElectricVehicle : public Vehicle {
//Todo 2.2: Implement the ElectricVehicle class
// there should be 5 functions in the class:
// 1. A constructor that takes the model, price, year of production, battery capacity, and range as arguments.
// 2. A function getBatteryCapacity() that returns the battery capacity.
// 3. A function getRange() that returns the range.
// 4. A function displayInfo() that displays the information of the electric vehicle.
// 5. A function calculateCost() that calculates the cost of the electric vehicle. The cost should be calculated by multiplying the price of the vehicle by the range of the vehicle.
private:
    int batteryCapacity;
    int range;
public:
    ElectricVehicle(const string& model, double price, int yearOfProduction, 
                      int batteryCapacity, int range);
    int getBatteryCapacity() const { return this->batteryCapacity; }
    int getRange() const { return this->range; }
    virtual void displayInfo() const override;
    virtual double calculateCost() const override;
};
#endif /* VEHICLE_H */ 