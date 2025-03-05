#include <string>
#include <iostream>

#include "vehicle.h"

using namespace std;

Vehicle::Vehicle(const string& licensePlate, const string& type): licensePlate(licensePlate), type(type) {
    cout << "[Creation] Vehicle " << licensePlate << " (" << type << ")." << endl;
}

string Vehicle::getLicensePlate() const {
    return licensePlate;
}

string Vehicle::getType() const
{
    return type;
}
