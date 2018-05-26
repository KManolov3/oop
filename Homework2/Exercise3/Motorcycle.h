#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle{
public:
        Motorcycle(const char* = "generic", const char* = "model 1", const char* = "white", size_t = 1900, double = 0, const char* = "chopper");
        Motorcycle(const Motorcycle&);
        Motorcycle& operator=(const Motorcycle&);
        ~Motorcycle();

        void setType(const char* type);
        const char* getType() const;

        void details() const;
private:
        char* type;

        void copy(const Motorcycle&);
};
