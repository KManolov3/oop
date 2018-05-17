#pragma once
#include <iostream>
#include "Product.cpp"

class Store{
    Product *products;
    int currentNumberOfProducts;
    int maxNumberOfProducts;
public:
    Store(int maxNumberOfProducts);
    Store(Store const&);
    ~Store();
    Store& operator=(Store const&);

    void addProduct();
    void deleteProduct(int SKU);
    void changeProduct(int SKU);
    void print() const;
private:
    bool isUnique(int) const;
    void copy(Store const&);
    void erase();
};
