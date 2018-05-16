#include "ElectricDevice.h"
#include <string.h>

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

    this->name = new char[getLength(name)+1];
    strcpy(this->name, name);
}

int ElectricDevice::getPowerConsumed() const{
    return powerConsumed;
}

void ElectricDevice::setPowerConsumed(powerConsumed){
    this->powerConsumed = powerConsumed;
}

void ElectricDevice::copy(ElectricDevice const& other){
    setName(other.name);
    setPowerConsumed(other.powerConsumed);
}

void ElectricDevice::erase(){
    delete[] name;
}


