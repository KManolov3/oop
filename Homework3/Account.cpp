#include <iostream>
#include <cstring>
#include "Account.h"

Account::Account(const char iban[], int ownerId, double amount) : ownerId(ownerId), amount(amount) {
    strcpy(this->iban, iban);
}

double Account::getBalance() const {
    return this->amount;
}
