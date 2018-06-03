#include <iostream>
#include <cstring>
#include "Bank.h"
#define NUM_CUSTOMERS 10
#define NUM_ACCOUNTS 10

Bank::Bank(const char* name, const char* address) :
maxCustomers(NUM_CUSTOMERS), curCustomers(0), maxAccounts(NUM_ACCOUNTS), curAccounts(0) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
    this->customers = new Customer*[maxCustomers];
    this->accounts = new Account*[maxAccounts];
}

Bank::Bank(const Bank& other){
    copy(other);
}

Bank& Bank::operator=(const Bank& other){
    if(this!=&other){
        erase();
        copy(other);
    }

    return *this;
}

Bank::~Bank(){
    erase();
}
