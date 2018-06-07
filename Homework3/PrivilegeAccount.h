#pragma once
#include <iostream>
#include "Account.h"

class PrivilegeAccount : public Account{
public:
    PrivilegeAccount(const char [] = "unspecified", int = 0, double = 0, double = 5);

    Account* clone() const;

    void deposit(double);
    bool withdraw(double);
    void display() const;

    double getOverdraft()const;
private:
    double overdraft;
};
