#include <iostream>
#include <vector>
#include "Account.cpp"
#include "CurrentAccount.cpp"
#include "SavingsAccount.cpp"
#include "PrivilegeAccount.cpp"
#include "Customer.cpp"

class Bank{
public:
    Bank(const char* = "default_name", const char* = "James Baucher 5");
    Bank(const Bank&);
    Bank& operator=(const Bank&);
    ~Bank();

    const char* getName() const;
    const char* getAddress() const;

    bool addCustomer(int, const char*, const char*);
    void listCustomers() const;
    bool deleteCustomer(int);

    bool addAccount(const char*, const char [], int, double);
    bool deleteAccount(const char []);
    void listAccounts() const;
    void listCustomerAccount(int) const;

    bool withdraw(const char[], double);
    bool deposit(const char[], double);
    bool transfer(const char[], const char[], double);
    void display() const;

private:
    char* name;
    char* address;
    std::vector<Customer*> customers;
    std::vector<Account*> accounts;

    int customerPos(int);
    int accountPos(const char[]);

    void copy(const Bank&);
    void erase();
};
