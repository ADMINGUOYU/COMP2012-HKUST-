#include <iostream>
#include "parking_lot.h"

using namespace std;

const int MAX_SIZE = 100;

int main() {
    // Create vehicles
    Vehicle* v1 = new Vehicle("AB1234", "Sedan");
    Vehicle* v2 = new Vehicle("XY789", "SUV");
    Vehicle* v3 = new Vehicle("CD5678", "Van");

    // Create first parking lot
    ParkingLot eastLot("East Wing", MAX_SIZE);

    // Create empty parking spots in the lot
    eastLot.createSpot("A-01");
    eastLot.createSpot("A-02");
    eastLot.createSpot("B-01");
    eastLot.createSpot("B-02");

    // Park vehicles in spots
    eastLot.addVehicle(v1, "A-01");
    eastLot.addVehicle(v2, "B-01");
    eastLot.addVehicle(v3, "A-01");  // This should fail as spot A-01 is already occupied
    eastLot.addVehicle(v1, "A-02");  // This should fail as vehicle AB1234 is already parked
    eastLot.addVehicle(v3, "B-03");  // This should fail as spot B-03 not found

    // Create another parking lot copying from the first one
    ParkingLot westLot = eastLot;
    westLot.setName("West Wing");

    // Manage vehicles in the second parking lot
    westLot.addVehicle(v1, "A-01");  // This should fail as vehicle AB1234 is already parked
    westLot.addVehicle(v3, "A-02");
    westLot.removeVehicle("B-01");
    westLot.removeVehicle("B-02");  // This should fail as spot B-02 is empty
    westLot.removeVehicle("C-02");  // This should fail as spot C-02 is not created

    // Display parking lots
    eastLot.display();
    westLot.display();

    // Cleanup
    delete v1;
    delete v2;
    delete v3;

    return 0;
}
