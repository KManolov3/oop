#include <iostream>
#include "Car.h"

Car::Car(const char* make, const char* model, const char* color, size_t year, double mileage) : Vehicle(make, model, color, year, mileage){
}

void Car::details() const{
    std::cout<<"This is a car with make "<<getMake()<<"\nModel "<<getModel()<<"\nColor "<<getColor()
    <<"\nMade in the year of "<<getYear()<<"\nWith a mileage of "<<getMileage()<<" miles\n";
}
