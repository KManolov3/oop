#include "HistoryEntry.h"
#include "NotSTL.cpp"
#include <iostream>

HistoryEntry::HistoryEntry(){
    this->url = nullptr;
}

HistoryEntry::HistoryEntry(char* url, int month){
    copyData(url, month);
}

HistoryEntry::HistoryEntry(HistoryEntry const& other){
    copy(other);
}

HistoryEntry::~HistoryEntry(){
    erase();
}

HistoryEntry& HistoryEntry::operator=(HistoryEntry const& other){
    if(this!=&other){
        erase();
        copy(other);
    }
    return *this;
}

void HistoryEntry::copy(HistoryEntry const& other){
    copyData(other.url, other.month);
}

void HistoryEntry::copyData(char* url, int month){
    this->url = new char[getLength(url) +1];
    copyString(this->url, url);

    this->month = month;
}

void HistoryEntry::erase(){
    delete[] url;
}

void HistoryEntry::print() const{
    std::cout<<"URL: ";
    printString(this->url);
    std::cout<<"\nMonth Accessed: ";
    printMonth(month);
}

void HistoryEntry::printMonth(int month) const{
    switch(month){
        case 1:
            std::cout<<"January\n";
            break;
        case 2:
            std::cout<<"February\n";
            break;
        case 3:
            std::cout<<"March\n";
            break;
        case 4:
            std::cout<<"April\n";
            break;
        case 5:
            std::cout<<"May\n";
            break;
        case 6:
            std::cout<<"June\n";
            break;
        case 7:
            std::cout<<"July\n";
            break;
        case 8:
            std::cout<<"August\n";
            break;
        case 9:
            std::cout<<"September\n";
            break;
        case 10:
            std::cout<<"October\n";
            break;
        case 11:
            std::cout<<"November\n";
            break;
        case 12:
            std::cout<<"December\n";
            break;
        default:
            std::cerr<<"Invalid month\n";
    }
}

void HistoryEntry::createEntry(){
    std::cout<<"Enter URL: ";
    url = inputUnspecifiedLengthString();

    std::cout<<"Enter month: ";
    std::cin>>month;
}


