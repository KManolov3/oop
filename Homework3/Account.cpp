#include <iostream>
#include <cstring>
#include "Account.h"

Account::Account(const char iban[], int ownerId, double amount) : ownerId(ownerId), amount(amount) {
    strcpy(this->iban, iban);
}

const char* Account::getIban() const{
    return this->iban;
}

int Account::getOwnerId() const{
    return this->ownerId;
}

/*
void Account::setIban(const char newIban[]){
    strcpy(iban, newIban);
}
*/

double Account::getBalance() const {
    return this->amount;
}
