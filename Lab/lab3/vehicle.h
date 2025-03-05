#include <string>
using namespace std;

class Vehicle {
private:
    string licensePlate;
    string type;
public:
    Vehicle(const string& licensePlate, const string& type);
    Vehicle(const Vehicle&) = delete;
    string getLicensePlate() const;
    string getType() const;
};
