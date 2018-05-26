#include <iostream>
#include "Vehicle.cpp"
#include "Motorcycle.cpp"
#include "Truck.cpp"
#include "Car.cpp"
int main()
{
    Car car1, car2("Audi", "C42", "Green", 1980, 10000);
    Motorcycle cycle1;
    Motorcycle cycle2(cycle1);
    Truck truck;
    car1 = car2;

    cycle2.details();
    car1.details();
    truck.details();

    return 0;
}
