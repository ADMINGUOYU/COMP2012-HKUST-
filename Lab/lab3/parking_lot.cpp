#include "parking_lot.h"
#include <iostream>

ParkingLot::ParkingLot(const string& name, int capacity) 
    :
    name(name),
    spots(nullptr),
    capacity(capacity),
    num_of_spots(0)
{
    // TODO 1: ParkingLot constructor
    /*
    Implement parkingLot::parkingLot.
        Print a message "[Creation] Parking Lot <name>".
        Create parkingSpot array with new keyword.
        Initialize every elements in parkingSpot array with nullptr.
    */
    //prints message
    std::cout << "[Creation] Parking Lot " << this->name << std::endl;

    //allocate memory
    this->spots = new ParkingSpot*[this->capacity];

    //initialize every pointer
    for (int i = 0; i < this->capacity; i++) this->spots[i] = nullptr;

    return;
}

ParkingLot::ParkingLot(const ParkingLot& lot) 
    :
    name(lot.name),
    spots(nullptr),
    capacity(lot.capacity),
    num_of_spots(0)
{
    // TODO 2: ParkingLot copy constructor
    /*
    Implement parkingLot::parkingLot (copy constructor).
        Print a message "[CopyCreation] Parking Lot <name>".
        Create parkingSpot array with new keyword.
        Initialize every elements in parkingSpot array with nullptr.
        Create spots with the same numbers and vehicle (if occupied) in const ParkingLot& lot.
        Use ParkingLot::createSpot when create new spots.
        Note: the vehicles in the original `ParkingLot` should NOT be deep copied.
    */
    //prints message
    std::cout << "[CopyCreation] Parking Lot " << this->name << std::endl;

    //allocate memory
    this->spots = new ParkingSpot*[this->capacity];

    //initialize every pointer
    for (int i = 0; i < this->capacity; i++) this->spots[i] = nullptr;

    //creates spots
    for (int i = 0; i < lot.num_of_spots; i++) this->createSpot(lot.spots[i]->getSpotNumber(), lot.spots[i]->getVehicle());

    return;
}

ParkingLot::~ParkingLot() {
    // TODO 3: ParkingLot destructor
    /*
    Implement parkingLot::~parkingLot.
        Print a message "[Destructor] Parking Lot <name>".
        Deallocate the memory allocated properly.
    */

    //delete parking lots (deleting nullptr is safe)
    for (int i = 0; i < this->capacity; i++) delete this->spots[i];

    //delete the array of pointers
    delete [] this->spots;

    //prints message
    std::cout << "[Destructor] Parking Lot " << this->name << std::endl;
    return;
}

void ParkingLot::createSpot(const string& spotNumber, Vehicle* vehicle) {
    if (num_of_spots >= capacity) {
        cout << "Cannot create more spots. Parking lot is at capacity." << endl;
        return;
    }
    
    spots[num_of_spots++] = new ParkingSpot(spotNumber, vehicle);
}

bool ParkingLot::addVehicle(Vehicle* vehicle, const string& spotNumber) {
    // TODO 4: addVehicle member function in parkingLot class
    /*
    Implement parkingLot::addVehicle.
        The target of this member function is to park a vehicle in the parking lot.
        If vehicle is invalid (nullptr), print a message "Invalid vehicle." then return false.
        If vehicle is already parked somewhere in this lot, print a message "Vehicle <name> is already parked in spot <number>." then return false.
        If the parkingSpot is occupied, print a message "Spot <number> is already occupied." then return false.
        If the parkingSpot is not found, print a message "Spot <number> not found in <lot_name>" then return false.
        Use related member function in ParkingSpot to finish the parking job, then return true.
        Note: In case of concurrent multiple errors, print only the one listed first above.
    */

    //checks vehicle validity
    if (nullptr == vehicle) { std::cout << "Invalid vehicle." << std::endl; return false; }

    //checks if the vehicle is already parked
    for (int i = 0; i < this->num_of_spots; i++)
    {
        if (vehicle == this->spots[i]->getVehicle())
        {
            //found
            std::cout << "Vehicle " << vehicle->getLicensePlate() << " is already parked in spot " << this->spots[i]->getSpotNumber() << "." << std::endl;
            return false;
        }
    }

    //tries to find the spot
    for (int i = 0; i < this->num_of_spots; i++)
    {
        if (spotNumber == this->spots[i]->getSpotNumber())
        {
            //spot is found
            if (this->spots[i]->isOccupied())
            {
                //if it is occupied
                std::cout << "Spot " << spotNumber << " is already occupied." << std::endl;
                return false;
            }
            else
            {
                //now parks the vehicle
                this->spots[i]->parkVehicle(vehicle);
                return true;
            }
        }
    }

    //spot not found
    std ::cout << "Spot " << spotNumber << " not found in " << this->name << std::endl;
    return false;
}

bool ParkingLot::removeVehicle(const string& spotNumber) {
    for (int i = 0; i < num_of_spots; i++) {
        if (spots[i] != nullptr && spots[i]->getSpotNumber() == spotNumber) {
            if (!spots[i]->isOccupied()) {
                cout << "Spot " << spotNumber << " is already empty." << endl;
                return false;
            }
            spots[i]->removeVehicle();
            return true;
        }
    }
    cout << "Spot " << spotNumber << " not found in " << name << endl;
    return false;
}

string ParkingLot::getName() const {
    return name;
}

void ParkingLot::setName(const string& lotName) {
    name = lotName;
}

void ParkingLot::display() const {
    cout << "========================================" << endl; 
    cout << "Parking Lot " << name << endl;
    for (int i = 0; i < num_of_spots; i++) {
        if (spots[i] != nullptr) {
            cout << i << ". " << spots[i]->getSpotNumber();
            if (spots[i]->isOccupied()) {
                cout << " - " << spots[i]->getVehicle()->getLicensePlate();
            } else {
                cout << " - Empty";
            }
            cout << endl;
        }
    }
    cout << "========================================" << endl;
}
