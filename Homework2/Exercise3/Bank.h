#include <iostream>
#include "Account.cpp"
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
    bool deleteAcccount(const char []);
    void listAccounts() const;
    void listCustomerAccount(int) const;

    bool transfer(const char[], const char[], double);
    void display() const;

private:
    char* name;
    char* address;
    Customer** customers;
    int maxCustomers;
    int curCustomers;
    Account** accounts;
    int maxAccounts;
    int curAccounts;

    void resizeCustomers();
    void resizeAccounts();

    void copy(const Bank&);
    void erase();
};
