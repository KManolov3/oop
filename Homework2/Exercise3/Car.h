#pragma once
#include "Vehicle.h"

class Car : public Vehicle{
public:
    Car(const char* = "generic", const char* = "model1", const char* = "white", size_t = 1900, double = 0);
    void details() const;
};
