#pragma once
#include <iostream>
#include "ElectricDevice.cpp"

class ElectricNet{
public:
    ElectricNet(size_t = 10);
    ElectricNet(ElectricNet const&);
    ~ElectricNet();
    ElectricNet& operator=(ElectricNet const&);

    ElectricNet& operator+(ElectricDevice&);
    ElectricNet& operator+=(ElectricDevice&);
    ElectricNet& operator-(ElectricDevice&);
    ElectricNet& operator-=(ElectricDevice&);
    const ElectricDevice& operator[](const char*) const;
    bool operator!() const;
    void operator++();
    bool operator--();

    size_t getMaxConsumption() const;
    void setMaxConsumption(size_t);
private:
    ElectricDevice *electricNet;
    size_t currentElectricNetSize;
    size_t maxElectricNetSize;
    size_t currentPowerConsumption;
    size_t maxPowerConsumption;


    bool isDeviceUnique(const char*)const;
    int findDevicePosition(const char*) const;
    void removeDevice(const char*);
    void addDevice(ElectricDevice&);
    void resizeElectricNet();
    void copy(ElectricNet const&);
};
