#pragma once
#include <iostream>
#define STANDARD_IBAN_LENGTH 34

class Account{
public:
    Account(const char [] = "unspecified", int = 0, double = 0);

    virtual void deposit(double) = 0;
    virtual bool withdraw(double) = 0;
    virtual void display() const = 0;

    double getBalance() const;
    //void setIban(const char []);
protected:
    char iban[STANDARD_IBAN_LENGTH];
    int ownerId;
    double amount;
};
