#pragma once
#include <iostream>

class Product{
    int SKU;
    char* brand;
    char* model;
    char* category;
    int price;
    int count;
    //The product we are defining is any type of computer.
    int screenSize; //In inches
    int RAM; //In MB
    int HD; //In GB
    double processorSpeed; //In Ghz

public:
    Product(int SKU, char* brand, char* model, char* category, int price, int count, int screenSize, int RAM, int HD, double processorSpeed);
    Product(Product const&);
    ~Product();
    Product& operator=(Product const&);

    void readProductInfo();
    void print() const;

    int getSKU() const;
    void setSKU(int SKU);
    char* getBrand() const;
    void setBrand(char* brand);
    char* getModel() const;
    void setModel(char* model);
    char* getCategory() const;
    void setCategory(char* category);
    int getPrice() const;
    void setPrice(int price);
    int getCount() const;
    void setCount(int count);
    int getScreenSize() const;
    void setScreenSize(int screenSize);
    int getRAM() const;
    void setRAM(int RAM);
    int getHD() const;
    void setHD(int HD);
    double getProcessorSpeed() const;
    void setProcessorSpeed(double processorSpeed);

private:
    void copy(Product const&);
    void copyData(int SKU, char* brand, char* model, char* category, int price, int count, int screenSize, int RAM, int HD, double processorSpeed);
    void erase();
};
