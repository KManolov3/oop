#pragma once
#include <iostream>
#define STANDARD_IBAN_LENGTH 34

class Account{
public:
    Account(const char [] = "unspecified", int = 0, double = 0);
    virtual Account* clone() const = 0;

    virtual void deposit(double) = 0;
    virtual bool withdraw(double) = 0;
    virtual void display() const = 0;

    double getBalance() const;
    const char* getIban() const;
    int getOwnerId() const;
protected:
    char iban[STANDARD_IBAN_LENGTH+1];
    int ownerId;
    double amount;
};
