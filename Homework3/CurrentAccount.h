#pragma once
#include <iostream>
#include "Account.h"

class CurrentAccount : public Account{
    void deposit(double);
    bool withdraw(double);
    void display() const;
};
