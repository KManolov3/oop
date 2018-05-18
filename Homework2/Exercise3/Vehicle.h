#pragma once
#include <iostream>

class Vehicle{
public:
    Vehicle(const char* = "generic", const char* = "model 1", const char* = "white", size_t, double);
    Vehicle(const Vehicle&);
    ~Vehicle();
    Vehicle& operator=(const Vehicle&);

    const char* getMake() const;
    void setMake(const char*);
    const char* getModel() const;
    void setModel(const char*) const;
    const char* getColor() const;
    void setColor (const char*) const;
    size_t getYear() const;
    void setYear(size_t) const;
    double getMileage() const;
    void setMileage(double) const;

    virtual void details() const;

private:
    char* make;
    char* model;
    char* color;
    size_t year;
    double mileage;

    void copy(const Vehicle&);
    void erase();
};
