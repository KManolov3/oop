#pragma once
#include <iostream>
#include "ElectricDevice.cpp"

class ElectricNet{
public:
    ElectricNet(int = 10);
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

    int getMaxConsumption() const;
    void setMaxConsumption(int);
private:
    ElectricDevice *electricNet;
    int currentElectricNetSize;
    int maxElectricNetSize;
    int currentPowerConsumption;
    int maxPowerConsumption;

    int findDevicePosition(const char*) const;
    void removeDevice(const char*);
    void addDevice(ElectricDevice&);
    void resizeElectricNet();
    void erase();
    void copy(ElectricNet const&);
};
