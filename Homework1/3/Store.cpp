#include "Store.h"
#include "NotSTL.h"
#define DEFAULT_MAX_NUMBER_PRODUCTS 10

Store::Store(int maxNumberOfProducts = DEFAULT_MAX_NUMBER_PRODUCTS){
    this->maxNumberOfProducts = maxNumberOfProducts;
    this->currentNumberOfProducts = 0;
    this->products = new Product[maxNumberOfProducts];
}

Store::Store(Store const& other){
    copy(other);
}

Store::~Store(){
    erase();
}

Store& Store::operator=(Store const& other){
    if(this!=&other){
        erase();
        copy(other);
    }

    return *this;
}

void Store::erase(){
    delete[] products;
}

void Store::copy(Store const& other){
    this->maxNumberOfProducts = other.maxNumberOfProducts;
    this->currentNumberOfProducts = other.currentNumberOfProducts;
    for(int i=0; i<other.currentNumberOfProducts; i++)
            this->products[i] = other.products[i];
}

void Store::addProduct(){
    if(currentNumberOfProducts == maxNumberOfProducts){
        std::cerr<<"Store is full, can't add a new product!\n";
        return;
    }

    int SKU;
    do{
        std::cout<<"Enter unique store keeping unit: ";
        std::cin>>SKU;
    }while(!isUnique(SKU));

    products[currentNumberOfProducts].readProductInfo();
    products[currentNumberOfProducts].setSKU(SKU);
    currentNumberOfProducts++;
}

bool Store::isUnique(int SKU) const{
    for(int i=0; i<currentNumberOfProducts; i++)
        if(products[i].getSKU() == SKU)
            return false;
    return true;
}

void Store::deleteProduct(int SKU){
    for(int i=0; i<currentNumberOfProducts; i++){
        if(products[i].getSKU() == SKU){
            products[i] = products[--currentNumberOfProducts];
            return;
        }
    }

    std::cerr<<"No product with standard keeping unit "<<SKU<<". Doing nothing.\n";
}

void Store::changeProduct(int SKU){
    for(int i=0; i<currentNumberOfProducts; i++){
        if(products[i].getSKU() == SKU){
            products[i].readProductInfo();
            return;
        }
    }

    std::cerr<<"No product with standard keeping unit "<<SKU<<". Doing nothing.\n";
}

void Store::print() const{
    for(int i=0; i<currentNumberOfProducts; i++)
        products[i].print();
}
