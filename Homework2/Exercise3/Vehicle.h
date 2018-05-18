#pragma once
#include <iostream>

class Vehicle{
public:
    Vehicle(const char* = "generic", const char* = "model 1", const char* = "white", size_t = 1900, double = 0);
    Vehicle(const Vehicle&);
    ~Vehicle();
    Vehicle& operator=(const Vehicle&);

    const char* getMake() const;
    void setMake(const char*);
    const char* getModel() const;
    void setModel(const char*);
    const char* getColor() const;
    void setColor (const char*);
    size_t getYear() const;
    void setYear(size_t);
    double getMileage() const;
    void setMileage(double);

    virtual void details() const = 0;

private:
    char* make;
    char* model;
    char* color;
    size_t year;
    double mileage;

    void copy(const Vehicle&);
    void erase();
};
