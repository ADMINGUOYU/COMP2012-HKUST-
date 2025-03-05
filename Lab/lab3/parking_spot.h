#include <string>

#include "vehicle.h"

using namespace std;

class ParkingSpot {
    private:
        string spotNumber;
        Vehicle* vehicle;
    public:
        ParkingSpot() = delete;
        ParkingSpot(const string& spotNumber, Vehicle* vehicle = nullptr);
        ParkingSpot(const ParkingSpot&) = delete;
        ~ParkingSpot();
        
        bool isOccupied() const;
        bool parkVehicle(Vehicle* vehicle);  // Returns true if successful
        Vehicle* removeVehicle();  // Returns removed vehicle pointer
        
        string getSpotNumber() const;
        Vehicle* getVehicle() const;
};
