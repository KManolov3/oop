#include <iostream>
#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(const char iban[], int ownerId, double amount, double overdraft) : Account(iban, ownerId, amount), overdraft(overdraft){

}

PrivilegeAccount::deposit(double amountToDeposit){
    this->amount+=amountToDeposit;
}

PrivilegeAccount::withdraw(double amountToWithdraw){
    if((this->amount + this->overdraft) - amountToWithdraw < 0)
        return false;

    this->amount-=amountToWithdraw;
    return true;
}

void PrivilegeAccount::display() const{
    std::cout<<"This is an account of type privilege account. It has IBAN: "<<this->iban<<"\nIt belong to a customer with id: "
    <<this->ownerId<<"\nIt has a current balance of "<<this->amount<<" eur.\n It has an allowed overdraft of "<<this->overdraft<<" eur.\n";
}

double PrivilegeAccount::getOverdraft() const{
    return this->overdraft;
}
