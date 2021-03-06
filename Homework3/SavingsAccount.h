#pragma once
#include <iostream>
#include "Account.h"

class SavingsAccount : public Account{
public:
    SavingsAccount(const char [] = "unspecified", int = 0, double = 0, double = 0);

    Account* clone() const;

    void deposit(double);
    bool withdraw(double);
    void display() const;

    double getInterestRate() const;
private:
    double interestRate;
};
