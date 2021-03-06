#pragma once
#include <iostream>
#include "Account.h"

class CurrentAccount : public Account{
public:
    CurrentAccount(const char [] = "unspecified", int = 0, double = 0);

    Account* clone() const;

    void deposit(double);
    bool withdraw(double);
    void display() const;
};
