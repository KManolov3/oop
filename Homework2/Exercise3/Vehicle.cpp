#include <iostream>
#include <cstring>
#include "Vehicle.h"

Vehicle::Vehicle(const char* make, const char* model, const char* color, size_t year, double mileage) : mileage(mileage), year(year) {
    this->make = new char[strlen(make) + 1];
    strcpy(this->make, make);
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
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
        std::cerr<<"Trying to set make to null pointer!\n";
        return;
    }

    if(this->make == nullptr || strlen(this->make) < strlen(make)){
        delete[] this->make;
        this->make = new char[strlen(make) + 1];
    }
    strcpy(this->make, make);
}

const char* Vehicle::getModel() const{
    return this->model;
}

void Vehicle::setModel(const char* model){
    if(model == nullptr){
        std::cerr<<"Trying to set model to null pointer!\n";
        return;
    }

    if(this->model == nullptr || strlen(this->model) < strlen(model)){
        delete[] this->model;
        this->model = new char[strlen(model) + 1];
    }
    strcpy(this->model, model);
}

const char* Vehicle::getColor() const{
    return this->color;
}

void Vehicle::setColor(const char* color){
    if(color == nullptr){
        std::cerr<<"Trying to set color to null pointer!\n";
        return;
    }

    if(this->color == nullptr || strlen(this->color) < strlen(color)){
        delete[] this->color;
        this->color = new char[strlen(color) + 1];
    }

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
    this->make = new char[strlen(other.make) + 1];
    strcpy(this->make, other.make);
    this->model = new char[strlen(other.model) + 1];
    strcpy(this->model, other.model);
    this->color = new char[strlen(other.color) + 1];
    strcpy(this->color, other.color);
    this->year = other.year;
    this->mileage = other.mileage;
}

void Vehicle::erase(){
    delete[] make;
    delete[] model;
    delete[] color;
}
