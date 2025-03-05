#include <string>

#include "parking_spot.h"

using namespace std;

class ParkingLot {
private:
    string name;
    ParkingSpot** spots;
    int capacity;
    int num_of_spots;
public:
    ParkingLot(const string& name, int capacity=100);
    ParkingLot(const ParkingLot& lot);
    ~ParkingLot();
    void createSpot(const string& spotNumber, Vehicle* vehicle = nullptr);
    bool addVehicle(Vehicle* vehicle, const string& spotNumber);
    bool removeVehicle(const string& spotNumber);
    string getName() const;
    void setName(const string& lotName);
    void display() const;
};
