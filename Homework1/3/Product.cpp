#include "Product.h"
#include "NotSTL.cpp"
#define DEFAULT_PRODUCT_STRING "blank"
#define DEFAULT_PRODUCT_STRING_LENGTH 5

Product::Product(int PKU = 0, char* brand = nullptr, char* model = nullptr, char* category = nullptr, int price = 0, int count = 0, int screenSize = 0, int RAM = 0, int HD =0, double processorSpeed = 0){
    copyData(PKU, brand, model, category, price, count, screenSize, RAM, HD, processorSpeed);
}

Product::Product(Product const& other){
    copy(other);
}

Product::~Product(){
    erase();
}

Product& Product::operator=(Product const& other){
    if(this!=&other){
        erase();
        copy(other);
    }
    return *this;
}

void Product::copy(Product const& other){
    copyData(other.SKU, other.brand, other.model, other.category, other.price, other.count, other.screenSize, other.RAM, other.HD, other.processorSpeed);
}

void Product::copyData(int SKU, char* brand, char* model, char* category, int price, int count, int screenSize, int RAM, int HD, double processorSpeed){
    setSKU(SKU);
    setBrand(brand);
    setModel(model);
    setCategory(category);
    setPrice(price);
    setCount(count);
    setScreenSize(screenSize);
    setRAM(RAM);
    setHD(HD);
    setProcessorSpeed(processorSpeed);
}

void Product::erase(){
    delete[] brand;
    delete[] model;
    delete[] category;
}

void Product::readProductInfo(){
    std::cout<<"Enter brand: ";
    brand = inputUnspecifiedLengthString();

    std::cout<<"Enter model: ";
    model = inputUnspecifiedLengthString();

    std::cout<<"Enter category: ";
    category = inputUnspecifiedLengthString();

    std::cout<<"Enter price: ";
    std::cin>>price;

    std::cout<<"Enter stock count: ";
    std::cin>>count;

    std::cout<<"Enter screen size in inches: ";
    std::cin>>screenSize;

    std::cout<<"Enter RAM in MBs: ";
    std::cin>>RAM;

    std::cout<<"Enter hard drive in GBs: ";
    std::cin>>HD;

    std::cout<<"Enter processor speed in Ghz: ";
    std::cin>>processorSpeed;
}

void Product::print() const{
    std::cout<<"SKU: "<<SKU<<std::endl;\
    std::cout<<"Brand: ";
    printString(brand);
    std::cout<<"\nModel: ";
    printString(model);
    std::cout<<"\nCategory: ";
    printString(category);
    std::cout<<"\nPrice: "<<price<<std::endl;
    std::cout<<"In stock: "<<count<<std::endl;
    std::cout<<"Screen Size: "<<screenSize<<" inches"<<std::endl;
    std::cout<<"RAM: "<<RAM<<" MBs"<<std::endl;
    std::cout<<"Hard Drive: "<<HD<<" GBs"<<std::endl;
    std::cout<<"Proccessor Speed: "<<processorSpeed<<" Ghz"<<std::endl;
}

int Product::getSKU() const{
    return SKU;
}

void Product::setSKU(int SKU){
    this->SKU = SKU;
}

char* Product::getBrand() const{
    return brand;
}

void Product::setBrand(char* brand){
    if(brand == nullptr){
        this->brand = new char[DEFAULT_PRODUCT_STRING_LENGTH + 1];
        copyString(this->brand, DEFAULT_PRODUCT_STRING);
        return;
    }
    delete brand;
    this->brand = new char[getLength(brand)];
    copyString(this->brand, brand);
}

char* Product::getModel() const{
    return model;
}

void Product::setModel(char* model){
    if(model == nullptr){
        this->model = new char[DEFAULT_PRODUCT_STRING_LENGTH + 1];
        copyString(this->model, DEFAULT_PRODUCT_STRING);
        return;
    }
    delete model;
    this->model = new char[getLength(model)];
    copyString(this->model, model);
}

char* Product::getCategory() const{
    return category;
}

void Product::setCategory(char* category){
    if(category == nullptr){
        this->category = new char[DEFAULT_PRODUCT_STRING_LENGTH + 1];
        copyString(this->category, DEFAULT_PRODUCT_STRING);
        return;
    }
    delete category;
    this->category = new char[getLength(category)];
    copyString(this->category, category);
}

int Product::getPrice() const{
    return price;
}

void Product::setPrice(int price){
    this->price = price;
}

int Product::getCount() const{
    return count;
}

void Product::setCount(int count){
    this->count = count;
}

int Product::getScreenSize() const{
    return screenSize;
}

void Product::setScreenSize(int screenSize){
    this->screenSize = screenSize;
}

int Product::getRAM() const{
    return RAM;
}

void Product::setRAM(int RAM){
    this->RAM = RAM;
}

int Product::getHD() const{
    return HD;
}

void Product::setHD(int HD){
    this->HD = HD;
}

double Product::getProcessorSpeed() const{
    return processorSpeed;
}

void Product::setProcessorSpeed(double processorSpeed){
    this->processorSpeed = processorSpeed;
}

