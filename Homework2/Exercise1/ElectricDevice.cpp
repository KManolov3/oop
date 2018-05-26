#include "ElectricDevice.h"
#include <cstring>

ElectricDevice::ElectricDevice(const char* name, size_t powerConsumed):powerConsumed(powerConsumed){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

ElectricDevice::ElectricDevice(ElectricDevice const& other){
    copy(other);
}

ElectricDevice::~ElectricDevice(){
    erase();
}

ElectricDevice& ElectricDevice::operator=(ElectricDevice const& other){
    if(this!=&other){
        erase();
        copy(other);
    }
    return *this;
}

const char* ElectricDevice::getName() const{
    return name;
}

void ElectricDevice::setName(const char* name){
    if(name == nullptr){
        std::cerr<<"Trying to set name to null pointer!\n";
        return;
    }

    if(this->name == nullptr || strlen(this->name) < strlen(name)){
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
    }

    strcpy(this->name, name);
}

size_t ElectricDevice::getPowerConsumed() const{
    return powerConsumed;
}

void ElectricDevice::setPowerConsumed(size_t powerConsumed){
    this->powerConsumed = powerConsumed;
}

void ElectricDevice::copy(ElectricDevice const& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->powerConsumed = other.powerConsumed;
}

void ElectricDevice::erase(){
    delete[] name;
}


