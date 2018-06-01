#pragma once
#include <iostream>

class Account{
public:
    Account(const char [] = "unspecified", int = 0, double = 0);

    virtual void deposit(double) = 0;
    virtual bool withdraw(double) = 0;
    virtual void display() const = 0;

    double getBalance() const;
protected:
    char iban[34];
    int ownerId;
    double amount;
};
