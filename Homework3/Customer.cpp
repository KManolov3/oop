#include <iostream>
#include <cstring>
#include "Customer.h"

Customer::Customer(int id, const char* name, const char* address) : id(id) {
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->address = new char[strlen(address)+1];
    strcpy(this->address, address);
}

Customer::Customer(const Customer& other){
    copy(other);
}

Customer::~Customer(){
    erase();
}

Customer& Customer::operator=(const Customer& other){
    if(this!=&other){
        erase();
        copy(other);
    }

    return *this;
}

int Customer::getId() const{
    return this->id;
}

const char* Customer::getName() const{
    return this->name;
}

const char* Customer::getAddress() const{
    return this->address;
}

void Customer::display() const{
    std::cout<<"This is a customer with id: "<<getId()<<"\nHe is called "<<getName()<<"\nThis customer's address is "<<getAddress()<<std::endl;
}

void Customer::copy(const Customer& other){
    this->id = other.id;
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->address = new char[strlen(other.address) + 1];
    strcpy(this->address, other.address);
}

void Customer::erase(){
    delete[] this->name;
    delete[] this->address;
}
