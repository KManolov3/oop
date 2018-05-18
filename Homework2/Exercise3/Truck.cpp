#include "Truck.h"

Truck::Truck(const char* make, const char* model, const char* color, size_t year, double mileage, size_t size) :
Vehicle(make, model, color, year, mileage) {
    this->size = size;
}

void Truck::details() const{
    std::cout<<"This is a car with make "<<getMake()<<"\nModel "<<getModel()<<"\nColor "<<getColor()
    <<"\nMade in the year of "<<getYear()<<"\nWith a mileage of "<<getMileage()<<" miles."<<"With a size of "<<getSize()<<" meters.\n";
}

size_t Truck::getSize() const{
    return this->size;
}

void Truck::setSize(size_t size){
    this->size = size
}

