#include "Vehicle.h"
using namespace std;
// ====== Vehicle class implementation ======
Vehicle::Vehicle(const string& model, double price, int yearOfProduction) 
    :
    model(model),
    price(price),
    yearOfProduction(yearOfProduction)
{
    // Todo 1: Implement the Vehicle constructor
    return;
}

// ====== CombustionVehicle class implementation======
CombustionVehicle::CombustionVehicle
(const string& model, double price, int yearOfProduction, double fuelConsumption, int emissionLevel) 
    :
    Vehicle(model, price, yearOfProduction),
    fuelConsumption(fuelConsumption),
    emissionLevel(emissionLevel)
{
    // Todo 2.1: Implement the CombustionVehicle constructor
    return;
}


void CombustionVehicle::displayInfo() const {
    cout << "Combustion Vehicle: " << model << ", Year of Production: " << yearOfProduction
         << ", Price: " << price << " hkd, Fuel Consumption: " << fuelConsumption 
         << " liters/100km, Emission Level: " << emissionLevel << endl;
}

double CombustionVehicle::calculateCost() const {
    // Assume average fuel price is 8 hkd/liter, annual driving distance is 15000 km
    double yearlyFuelCost = (fuelConsumption * 8.0 * 15000) / 100;
    return price + yearlyFuelCost;
}

// ====== ElectricVehicle class implementation======
ElectricVehicle::ElectricVehicle
(const string& model, double price, int yearOfProduction, int batteryCapacity, int range) 
    :
    Vehicle(model, price, yearOfProduction),
    batteryCapacity(batteryCapacity),
    range(range)
{
    // Todo 2.2: Implement the ElectricVehicle constructor
    // Make sure to call the base class constructor and initialize additional data members
    return;
}

void ElectricVehicle::displayInfo() const {
    cout << "Electric Vehicle: " << model << ", Year of Production: " << yearOfProduction
         << ", Price: " << price << " hkd, Battery Capacity: " << batteryCapacity
         << "kWh, Range: " << range << "km" << endl;
}
double ElectricVehicle::calculateCost() const {
    // Todo 2.2: Implement the calculateCost method for ElectricVehicle
    // Assume electricity price is 1 hkd/kWh, annual driving distance is 15000 km
    // Calculate and return the total cost (price + annual electricity costs), noted that for simplicity, we just need to add one year electricity cost
    // The calculation formula is : yearlyElectricityCost = (batteryCapacity * 1.0 * 15000) / range
    double yearlyElectricityCost = (batteryCapacity * 1.0 * 15000) / range;
    return (this->price + yearlyElectricityCost);
} 