#include <iostream>
#include "Account.cpp"
#include "CurrentAccount.cpp"

int main() {
/*
    CurrentAccount cur("gosho", 1, 2);
    CurrentAccount cur2(cur);
    cur2.display();
    cur.setIban("pesho");
    cur2.display();
    cur.display();
*/
    Account* acc = new Account[10];


    return 0;
}
