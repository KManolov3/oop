#pragma once
#include <iostream>

class Customer{
public:
    Customer(int = 0, const char* = "no name specified", const char* = "no address specified");
    Customer(const Customer&);
    ~Customer();
    Customer& operator=(const Customer&);

    int getId() const;
    const char* getName() const;
    const char* getAddress() const;
    void display() const;

private:
    int id;
    char* name;
    char* address;
    void copy(const Customer&);
    void erase();
};
