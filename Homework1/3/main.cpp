#include <iostream>
#include "Store.cpp"

int main(){
    Store store;
    char action;
    std::cout<<"Welcome to the computer store!";
    int SKU;
    do{
        std::cout<<"What do you want to do?\nA - Add new product\nX - Delete Product\nC - Change Product\nD - Display Products\nQ - Quit\n";
        std::cin>>action;
        if(action == 'A')
            store.addProduct();
        else if(action == 'X'){
            std::cout<<"Enter store keeping unit of item you wish to delete: ";
            std::cin>>SKU;
            store.deleteProduct(SKU);
        } else if(action == 'C'){
            std::cout<<"Enter store keeping unit of item you wish to change: ";
            std::cin>>SKU;
            store.changeProduct(SKU);
        } else if(action == 'D')
            store.print();
    }while(action!='Q');

    return 0;
}
