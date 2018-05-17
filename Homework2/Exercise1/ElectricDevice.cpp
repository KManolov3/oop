#include "ElectricDevice.h"
#include <cstring>

ElectricDevice::ElectricDevice(const char* name, int powerConsumed):powerConsumed(powerConsumed){
    setName(name);
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
    if(name==nullptr)
        return;

    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

int ElectricDevice::getPowerConsumed() const{
    return powerConsumed;
}

void ElectricDevice::setPowerConsumed(int powerConsumed){
    this->powerConsumed = powerConsumed;
}

void ElectricDevice::copy(ElectricDevice const& other){
    setName(other.name);
    setPowerConsumed(other.powerConsumed);
}

void ElectricDevice::erase(){
    delete[] name;
}


