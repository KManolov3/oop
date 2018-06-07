#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const char iban[], int ownerId, double amount, double interestRate) : Account(iban, ownerId, amount), interestRate(interestRate) {
}

Account* SavingsAccount::clone() const{
    return new SavingsAccount(*this);
}

void SavingsAccount::deposit(double amountToDeposit){
    this->amount+=amountToDeposit;
}

bool SavingsAccount::withdraw(double amountToWithdraw){
    if(this->amount - amountToWithdraw < 0)
        return false;

    this->amount-=amountToWithdraw;
    return true;
}

void SavingsAccount::display() const{
    std::cout<<"This is an account of type savings account. It has IBAN: "<<this->iban<<"\nIt belong to a customer with id: "
    <<this->ownerId<<"\nIt has a current balance of "<<this->amount<<" eur.\nIt has an yearly interest rate of "<<this->interestRate<<"%.\n";
}

double SavingsAccount::getInterestRate() const{
    return this->interestRate;
}
