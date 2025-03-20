#include "Factory.h"
#include <iostream>

using namespace std;

int main() {
    Factory factory(50);
    
    factory.addVehicle(new CombustionVehicle("BYD Qin", 120000, 2023, 5.8, 6));
    factory.addVehicle(new CombustionVehicle("Toyota RAV4", 220000, 2022, 7.2, 5));
    factory.addVehicle(new ElectricVehicle("Tesla Model 3", 280000, 2023, 60, 550));
    factory.addVehicle(new ElectricVehicle("BYD K9", 200000, 2021, 350, 300));
   
    // List all vehicles
    cout << "All vehicles in the factory:" << endl;
    factory.listAllVehicles();
    cout << endl;

    // List all combustion vehicles
    cout << "Combustion vehicles in the factory:" << endl;
    factory.listCombustionVehicles();
    cout << endl;

    // List all electric vehicles
    cout << "Electric vehicles in the factory:" << endl;
    factory.listElectricVehicles();
    cout << endl;

    // Calculate total costs
    cout << "Total cost of combustion vehicles: " << factory.calculateTotalCombustionCost() << " hkd" << endl;
    cout << "Total cost of electric vehicles: " << factory.calculateTotalElectricCost() << " hkd" << endl;
    cout << "Total cost of all vehicles: " << factory.calculateTotalCost() << " hkd" << endl;

    return 0;
} 