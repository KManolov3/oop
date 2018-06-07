#include <iostream>
#include <cstring>
#include <vector>
#include "Bank.h"

Bank::Bank(const char* name, const char* address) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

Bank::Bank(const Bank& other){
    copy(other);
}

Bank& Bank::operator=(const Bank& other){
    if(this!=&other){
        erase();
        copy(other);
    }

    return *this;
}

Bank::~Bank(){
    erase();
}

const char* Bank::getName() const{
    return this->name;
}

const char* Bank::getAddress() const{
    return this->address;
}

void Bank::listCustomers() const{
    std::cout<<"The bank has the following customers: \n";
    for(int i=0; i<this->customers.size(); i++){
        this->customers[i]->display();
    }
}

bool Bank::addCustomer(int id, const char* name, const char* address){
    if(customerPos(id) == -1){
        this->customers.push_back(new Customer(id, name, address));
        return true;
    }
    return false;
}

bool Bank::deleteCustomer(int ownerId) {
    int customerPos = this->customerPos(ownerId);

    if(customerPos == -1)
        return false;

    this->customers.erase(this->customers.begin() + customerPos);

    for(int i=0; i<this->accounts.size(); i++){
        if(this->accounts[i]->getOwnerId() == ownerId){
            this->accounts.erase(this->accounts.begin() + i);
            --i;
        }
    }

    return true;
}

int Bank::customerPos(int id){
    for(int i=0; i<this->customers.size(); i++){
        if(this->customers[i]->getId() == id)
            return i;
    }

    return -1;
}

bool Bank::addAccount(const char* accountType, const char iban[], int ownerId, double amount){
    if(customerPos(ownerId) == -1){
        std::cerr<<"Trying to add an account to an invalid customer!\n";
        return false;
    }

    if(accountPos(iban) != -1){
        std::cerr<<"Trying to create an account that already exists!\n";
        return false;
    }

    if(strcmp(accountType, "CurrentAccount") == 0){
        this->accounts.push_back(new CurrentAccount(iban, ownerId, amount));
    } else if(strcmp(accountType, "SavingsAccount") == 0){
        this->accounts.push_back(new SavingsAccount(iban, ownerId, amount));
    } else if(strcmp(accountType, "PrivilegeAccount") == 0){
        this->accounts.push_back(new PrivilegeAccount(iban, ownerId, amount));
    } else {
        std::cerr<<"Invalid account type!\n";
        return false;
    }

    return true;
}

bool Bank::deleteAccount(const char iban[]){
    int position = accountPos(iban);

    if(position == -1){
        std::cerr<<"Trying to delete an account that does not exist!\n";
        return false;
    }

    this->accounts.erase(this->accounts.begin() + position);
    return true;
}

void Bank::listAccounts()const{
    std::cout<<"The bank has the following accounts: \n";

    for(int i=0; i<this->accounts.size(); i++)
        this->accounts[i]->display();
}

int Bank::accountPos(const char iban[]){
    for(int i=0; i<accounts.size(); i++){
        if(strcmp(this->accounts[i]->getIban(), iban) == 0)
            return i;
    }

    return -1;
}

void Bank::listCustomerAccount(int customerId) const{
    std::cout<<"The customer with id "<<customerId<<" has the following accounts:\n";
    for(int i=0; i<this->accounts.size(); i++)
        if(this->accounts[i]->getOwnerId() == customerId)
            this->accounts[i]->display();
}

bool Bank::withdraw(const char iban[], double amount){
    Account *acc=nullptr;
    for(int i=0; i<this->accounts.size(); i++){
        if(strcmp(this->accounts[i]->getIban(), iban) == 0){
            acc = this->accounts[i];
            break;
        }
    }

    if(acc == nullptr){
        std::cerr<<"Invalid account!\n";
        return false;
    }

    if(!acc->withdraw(amount))
        return false;

    return true;
}

bool Bank::deposit(const char iban[], double amount){
    Account *acc=nullptr;
    for(int i=0; i<this->accounts.size(); i++){
        if(strcmp(this->accounts[i]->getIban(), iban) == 0){
            acc = this->accounts[i];
            break;
        }
    }

    if(acc == nullptr){
        std::cerr<<"Invalid account!\n";
        return false;
    }

    acc->deposit(amount);

    return true;
}

bool Bank::transfer(const char ibanFrom[], const char ibanTo[], double amount){
    Account *from=nullptr, *to=nullptr;
    for(int i=0; i<this->accounts.size(); i++){
        if(strcmp(this->accounts[i]->getIban(), ibanFrom) == 0){
            from = this->accounts[i];
        }
        if(strcmp(this->accounts[i]->getIban(), ibanTo) == 0){
            to = this->accounts[i];
        }
    }
    if(from == nullptr || to == nullptr){
        std::cerr<<"Invalid accounts!\n";
        return false;
    }

    if(!from->withdraw(amount))
        return false;

    to->deposit(amount);
    return true;
}

void Bank::display() const{
    std::cout<<"This is a bank with name "<<this->getName()
    <<"\nIt is located on address "<<this->getAddress()
    <<"\nIt has "<<(int) this->customers.size()<<" customers, as well as "
    <<(int) this->accounts.size()<<" accounts\n";
}

void Bank::copy(const Bank& other){
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->address = new char[strlen(other.address) + 1];
    strcpy(this->address, other.address);

    for(int i=0; i<other.customers.size(); i++)
        this->customers.push_back(new Customer(*(other.customers[i])));

    for(int i=0; i<other.accounts.size(); i++)
        this->accounts.push_back(other.accounts[i]->clone());
}

void Bank::erase(){
    delete[] this->name;
    delete[] this->address;

    for(int i=0; i<this->customers.size(); i++)
        delete this->customers[i];
    this->customers.clear();

    for(int i=0; i<this->accounts.size(); i++){
        delete this->accounts[i];
    }
    this->accounts.clear();
}
