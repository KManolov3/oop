#include <iostream>
#include <cstring>
#include "Motorcycle.h"

Motorcycle::Motorcycle(const char* make, const char* model, const char* color, size_t year, double mileage, const char* type) : Vehicle(make, model, color, year, mileage){
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

Motorcycle::Motorcycle(const Motorcycle& other):Vehicle(other){
    copy(other);
}

Motorcycle::~Motorcycle(){
    delete[] this->type;
}

Motorcycle& Motorcycle::operator=(const Motorcycle& other){
    delete[] this->type;
    Vehicle::operator=(other);
    copy(other);
}

void Motorcycle::setType(const char* type){
    if(type == nullptr) {
            std::cerr<<"Trying to set type to null pointer!\n";
            return;
    }

    if(this->type == nullptr || strlen(this->type) < strlen(type)){
        delete[] this->type;
        this->type = new char[strlen(type) + 1];
    }

    strcpy(this->type, type);
}

const char* Motorcycle::getType() const {
    return this->type;
}

void Motorcycle::details() const{
    std::cout<<"This is a motorcycle with make "<<getMake()<<"\nModel "<<getModel()<<"\nColor "<<getColor()
    <<"\nMade in the year of "<<getYear()<<"\nIt is of type "<<getType()<<std::endl;
}

void Motorcycle::copy(const Motorcycle& other){
    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);
}
