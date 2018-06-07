#include <iostream>
#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(const char iban[], int ownerId, double amount) : Account(iban, ownerId, amount) {
}

Account* CurrentAccount::clone() const{
    return new CurrentAccount(*this);
}

void CurrentAccount::deposit(double amountToDeposit){
    this->amount+=amountToDeposit;
}

bool CurrentAccount::withdraw(double amountToWithdraw){
    if(this->amount - amountToWithdraw < 0)
        return false;

    this->amount-=amountToWithdraw;
    return true;
}

void CurrentAccount::display() const{
    std::cout<<"This is an account of type current account. It has IBAN: "<<this->iban<<"\nIt belong to a customer with id: "
    <<this->ownerId<<"\nIt has a current balance of "<<this->amount<<" eur.\n";
}
