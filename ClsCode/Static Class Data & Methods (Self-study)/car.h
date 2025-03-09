#include <iostream>     /* File: car.h */
using namespace std;

class Car               
{
  public:
    Car()  { ++num_cars; }
    ~Car() { --num_cars; }

    void drive(int km) { total_km += km; }
    static int cars_still_running() { return num_cars; }

  private:
    static int num_cars;
    int total_km = 0;
};
