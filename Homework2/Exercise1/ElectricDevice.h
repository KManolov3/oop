#pragma once
#include <iostream>

class ElectricDevice{
public:
    ElectricDevice(const char* = "Electric", size_t = 5);
    ElectricDevice(ElectricDevice const&);
    ~ElectricDevice();
    ElectricDevice& operator=(ElectricDevice const&);

    const char* getName() const;
    void setName(const char*);
    size_t getPowerConsumed() const;
    void setPowerConsumed(size_t);

private:
    char *name;
    size_t powerConsumed;

    void copy(ElectricDevice const&);
    void erase();
};
