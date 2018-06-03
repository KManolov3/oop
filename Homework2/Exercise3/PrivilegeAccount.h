#pragma once
#include <iostream>
#include "Account.h"

class PrivilegeAccount{
public:
    PrivilegeAccount(const char [] = "unspecified", int = 0, double = 0, double = 0);

    void deposit(double);
    bool withdraw(double);
    void display() const;

    double getOverdraft()const;
private:
    double overdraft;
};
