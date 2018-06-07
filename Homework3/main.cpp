#include <iostream>
#include <string>
#include "Bank.cpp"

int main() {
    Bank b("OBB", "Gosho st.");

    int selectOperation=0;

    std::cout<<"Menu: \n"<<
        "1 List customers\n2 Add new customer\n3 Delete customer\n4 List all accounts\n"<<
        "5 List customer accounts\n6 Add new account\n7 Delete account\n8 Withdraw from account\n"<<
        "9 Deposit to account\n10 Transfer\n11 Display info for the bank\n12 Quit\n";

    while(selectOperation!=12){
        std::cout<<"Please select the operation you wish to perform\n";
        std::cin>>selectOperation;

        int customerId;
        std::string name, address, accountType;
        char iban[STANDARD_IBAN_LENGTH + 1], ibanFrom[STANDARD_IBAN_LENGTH + 1], ibanTo[STANDARD_IBAN_LENGTH + 1];
        double amount;
        switch(selectOperation){
            case 1:
                b.listCustomers();
                break;
            case 2:
                std::cout<<"Insert customer id: ";
                std::cin>>customerId;
                std::cout<<"Insert customer name: ";
                std::cin.ignore();
                getline(std::cin, name);
                std::cout<<"Insert customer address: ";
                getline(std::cin, address);
                b.addCustomer(customerId, name.c_str(), address.c_str());
                break;
            case 3:
                std::cout<<"Insert customer id to be deleted: ";
                std::cin>>customerId;
                b.deleteCustomer(customerId);
                break;
            case 4:
                b.listAccounts();
                break;
            case 5:
                std::cout<<"Insert customer id: ";
                std::cin>>customerId;
                b.listCustomerAccount(customerId);
                break;
            case 6:
                std::cout<<"Insert account type: ";
                std::cin.ignore();
                getline(std::cin, accountType);
                std::cout<<"Insert iban: ";
                std::cin>>iban;
                std::cout<<"Insert owner id: ";
                std::cin>>customerId;
                std::cout<<"Insert amount to be opened with: ";
                std::cin>>amount;
                b.addAccount(accountType.c_str(), iban, customerId, amount);
                break;
            case 7:
                std::cout<<"Insert iban of account to be deleted: ";
                std::cin>>iban;
                b.deleteAccount(iban);
                break;
            case 8:
                std::cout<<"Insert iban of account from which to withdraw: ";
                std::cin>>iban;
                std::cout<<"Insert amount to withdraw: ";
                std::cin>>amount;
                b.withdraw(iban, amount);
                break;
            case 9:
                std::cout<<"Insert iban of account in which to deposit: ";
                std::cin>>iban;
                std::cout<<"Insert amount to deposit: ";
                std::cin>>amount;
                b.deposit(iban, amount);
                break;
            case 10:
                std::cout<<"Insert iban of account from which to withdraw: ";
                std::cin>>ibanFrom;
                std::cout<<"Insert iban of account in which to deposit: ";
                std::cin>>ibanTo;
                std::cout<<"Insert amount to transfer: ";
                std::cin>>amount;
                b.transfer(ibanFrom, ibanTo, amount);
                break;
            case 11:
                b.display();
            case 12:
                break;
            default:
                std::cout<<"No such operation!\n";
                break;
        }

    }

    return 0;
}
