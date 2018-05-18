#include "Motorcycle.h"
#include <cstring>

Motorcycle::Motorcycle(const char* make, const char* model, const char* color, size_t year, double mileage, const char* type) : Vehicle(make, model, color, year, mileage){
    setType(type);
}

Motorcycle::Motorcycle(const Motorcycle& other):Vehicle(other){
    setType(other.getType());
}

Motorcycle::~Motorcycle(){
    delete[] type;
}

Motorcycle& Motorcycle::operator=(const Motorcycle& other){
    Vehicle::operator=(other);
    delete[] type;
    setType(other.getType());
}

void Motorcycle::setType(const char* type){
    if(type == nullptr) {
            type = nullptr;
            return;
    }

    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

const char* Motorcycle::getType() const {
    return type;
}

void Motorcycle::details() const{
    std::cout<<"This is a car with make "<<getMake()<<"\nModel "<<getModel()<<"\nColor "<<getColor()
    <<"\nMade in the year of "<<getYear()<<"\nIt is of type "<<getType();
}
