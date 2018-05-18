#pragma once
#include <iostream>
#include "Vehicle.cpp"

class Car : public Vehicle{
public:
    Car(const char* = "generic", const char* = "model 1", const char* = "white", size_t = 1900, double = 0);
    void details() const;
};
