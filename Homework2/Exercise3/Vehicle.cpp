#include <iostream>
#include "Vehicle.h"

Vehicle::Vehicle(const char* make, const char* model, const char* color, size_t year, double mileage) : year(year), mileage(mileage) {
    setMake(make);
    setModel(model);
    setColor(color);
}

Vehicle::Vehicle(const Vehicle& other){
    copy(other);
}

Vehicle::~Vehicle(){
    erase();
}

Vehicle& Vehicle::operator=(const Vehicle& other){
    if(this!=&other){
        erase();
        copy(other);
    }

    return *this;
}

const char* getMake()const{
    return this->make;
}

void setMake(const char* make){
    if(make == nullptr){
        std::cerr<<"Trying to set make to nullptr. Off with you!"<<std::endl;
        return;
    }
    this->make = new char[strlen(make) + 1];
    strcpy(this->make, make);
}

const char* getModel() const{
    return this->model;
}

void setModel(const char* model){
    if(model == nullptr){
        std::cerr<<"Trying to set model to nullptr. Off with you!"<<std::endl;
        return;
    }
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
}

const char* getColor() const{
    return this->color;
}

void setColor(const char* color){
    if(color == nullptr){
        std::cerr<<"Trying to set color to nullptr. Off with you!"<<std::endl;
        return;
    }
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
}

size_t getYear() const{
    return this->year;
}

void Vehicle::copy(const Vehicle& other){
    setMake(other.make);
    setModel(other.model);
    setColor(other.color);
    this->year = other.year;
    this->mileage = other.mileage;
}

void Vehicle::erase(){
    delete[] make;
    delete[] model;
    delete[] color;
}


