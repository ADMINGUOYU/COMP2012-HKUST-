#include "car.h" /* File: test-car.cpp */
int Car::num_cars = 0; // Define + initialize static class member

int main()
{
    cout << Car::cars_still_running() << endl;
    Car vw;  vw.drive(1000); 
    Car bmw; bmw.drive(10);
    cout << Car::cars_still_running() << endl;

    Car *cp = new Car[100];
    cout << Car::cars_still_running() << endl;

    {
        Car kia; kia.drive(400);
        cout << Car::cars_still_running() << endl;
    }
    cout << Car::cars_still_running() << endl;
    delete [] cp;
    cout << Car::cars_still_running() << endl; return 0;
}
