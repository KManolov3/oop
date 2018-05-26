#pragma once
#include "Vehicle.h"

class Truck : public Vehicle{
public:
    Truck(const char* = "generic", const char* = "model 1", const char* = "white", size_t = 1900, double = 0, size_t = 5);
    void details() const;

    size_t getSize() const;
    void setSize(size_t size);
private:
    size_t size;
};
