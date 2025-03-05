#include <iostream>

#include "parking_spot.h"

using namespace std;

ParkingSpot::ParkingSpot(const string& spotNumber, Vehicle* vehicle) : spotNumber(spotNumber), vehicle(vehicle) {
    if (vehicle == nullptr) {
        cout << "[Creation] Empty ParkingSpot " << spotNumber << endl;
    } else {
        cout << "[Creation] ParkingSpot " << spotNumber <<" with vehicle " << vehicle->getLicensePlate() << endl;
    }
}

ParkingSpot::~ParkingSpot() {
}

bool ParkingSpot::isOccupied() const {
    return vehicle != nullptr;
}

bool ParkingSpot::parkVehicle(Vehicle* newVehicle) {
    if (isOccupied() || newVehicle == nullptr) {
        return false;
    }
    vehicle = newVehicle;
    cout << "[Park] Vehicle " << vehicle->getLicensePlate() << " in spot " << spotNumber << endl;
    return true;
}

Vehicle* ParkingSpot::removeVehicle() {
    if (!isOccupied()) {
        return nullptr;
    }
    Vehicle* removed = vehicle;
    cout << "[Remove] Vehicle " << removed->getLicensePlate() << " from spot " << spotNumber << endl;
    vehicle = nullptr;
    return removed;
}

string ParkingSpot::getSpotNumber() const {
    return spotNumber;
}

Vehicle* ParkingSpot::getVehicle() const {
    return vehicle;
}
