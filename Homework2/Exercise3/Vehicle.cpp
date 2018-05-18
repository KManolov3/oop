#include <iostream>
#include "Vehicle.h"
#include <cstring>

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

const char* Vehicle::getMake() const{
    return this->make;
}

void Vehicle::setMake(const char* make){
    if(make == nullptr){
        make = nullptr;
        return;
    }
    this->make = new char[strlen(make) + 1];
    strcpy(this->make, make);
}

const char* Vehicle::getModel() const{
    return this->model;
}

void Vehicle::setModel(const char* model){
    if(model == nullptr){
        model = nullptr;
        return;
    }
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
}

const char* Vehicle::getColor() const{
    return this->color;
}

void Vehicle::setColor(const char* color){
    if(color == nullptr){
        color = nullptr;
        return;
    }
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
}

size_t Vehicle::getYear() const{
    return this->year;
}

void Vehicle::setYear(size_t year){
    this->year = year;
}

double Vehicle::getMileage() const{
    return mileage;
}

void Vehicle::setMileage(double mileage){
    this->mileage = mileage;
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


