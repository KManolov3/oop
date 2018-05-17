#include "ElectricNet.h"
#include <cstring>

ElectricNet::ElectricNet(int maxPowerConsumption) :
currentElectricNetSize(0), maxElectricNetSize(10), currentPowerConsumption(0), maxPowerConsumption(maxPowerConsumption)
{
    electricNet=new ElectricDevice[maxElectricNetSize];
}

ElectricNet::ElectricNet(ElectricNet const& other){
    copy(other);
}

ElectricNet::~ElectricNet(){
    erase();
}

ElectricNet& ElectricNet::operator=(ElectricNet const& other){
    if(this != &other){
        erase();
        copy(other);
    }

    return *this;
}

ElectricNet& ElectricNet::operator+(ElectricDevice& newDevice){
    addDevice(newDevice);

    // TODO: Add a checkIfNameUnique function
    // TODO: Test if can add const Object to non-const Object*
    // TODO: Make definitely non-negative values of type size_t
    // TODO: Inline erase method

    return *this;
}

ElectricNet& ElectricNet::operator+=(ElectricDevice& newDevice){
    return operator+(newDevice);
}

ElectricNet& ElectricNet::operator-(ElectricDevice& device){
    removeDevice(device.getName());

    return *this;
}

ElectricNet& ElectricNet::operator-=(ElectricDevice& device){
    operator-(device);
}

const ElectricDevice& ElectricNet::operator[](const char* deviceName) const{
    int devicePosition = findDevicePosition(deviceName);

    if(devicePosition != -1)
        return electricNet[devicePosition];

    std::cerr<<"No device with that name in current electric network. Returning nullptr\n";
    return nullptr;
}

bool ElectricNet::operator!() const{
    if(currentElectricNetSize>0)
        return true;
    return false;
}

void ElectricNet::operator++(){
    maxPowerConsumption*=2;
}

bool ElectricNet::operator--(){
    if(currentPowerConsumption < maxPowerConsumption/2){
        maxPowerConsumption/=2;
        return true;
    }
    return false;
}

int ElectricNet::getMaxConsumption() const{
    return maxPowerConsumption;
}

void ElectricNet::setMaxConsumption(int maxPowerConsumption){
    this->maxPowerConsumption = maxPowerConsumption;
}

int ElectricNet::findDevicePosition(const char* deviceName) const{
    for(int i=0; i<currentElectricNetSize; i++){
        if(strcmp(electricNet[i].getName(), deviceName) == 0){
            return i;
        }
    }
}

void ElectricNet::removeDevice(const char* name){
    int devicePosition = findDevicePosition(name);

    if(devicePosition == -1) {
        std::cerr<<"Failed to remove device with name "<<name<<". Device is not in the electric net.\n";
        return;
    }

    ElectricDevice toBeRemoved = electricNet[devicePosition];
    currentPowerConsumption -= toBeRemoved.getPowerConsumed();
    electricNet[devicePosition] = electricNet[--currentElectricNetSize];
    delete &toBeRemoved;
}

void ElectricNet::addDevice(ElectricDevice& newDevice) {
    if(currentPowerConsumption + newDevice.getPowerConsumed() > maxPowerConsumption){
        std::cerr<<"Failed to add device with name "<<newDevice.getName()<<". The grid cannot support that big of a power consumption!\n";
        return;
    }

    if(currentElectricNetSize==maxElectricNetSize)
        resizeElectricNet();

    electricNet[currentElectricNetSize++] = newDevice;
    currentPowerConsumption+=newDevice.getPowerConsumed();
}

void ElectricNet::resizeElectricNet() {
    ElectricDevice* holder = electricNet;
    electricNet = new ElectricDevice[maxElectricNetSize*=2];

    for(int i=0; i<currentElectricNetSize; i++){
        electricNet[i] = holder[i];
    }

    delete[] holder;
}

void ElectricNet::erase() {
    delete[] electricNet;
}

void ElectricNet::copy(ElectricNet const& other){
    currentElectricNetSize = other.currentElectricNetSize;
    maxElectricNetSize = other.maxElectricNetSize;
    electricNet = new ElectricDevice[other.maxElectricNetSize];
    for(int i=0; i<currentElectricNetSize; i++){
        electricNet[i] = other.electricNet[i];
    }
    currentPowerConsumption = other.currentPowerConsumption;
    maxPowerConsumption = other.maxPowerConsumption;
}
