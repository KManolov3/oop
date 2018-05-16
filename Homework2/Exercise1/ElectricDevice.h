#pragma once
#include <iostream>

class ElectricDevice{
public:
    ElectricDevice(const char* = "Electric", int = 5);
    ElectricDevice(ElectricDevice const&);
    ~ElectricDevice();
    ElectricDevice& operator=(ElectricDevice const&);

    const char* getName() const;
    void setName(const char*);
    int getPowerConsumed() const;
    void setPowerConsumed(int);

private:
    char *name;
    int powerConsumed;

    void copy(ElectricDevice const&);
    void erase();
}
