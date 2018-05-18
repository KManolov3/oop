#include <iostream>
#include "Settings.h"

int main(){
    Settings<int> settings(1), settings3;
    Settings<int> settings2 = settings;
    settings3 = settings;

    std::cout<<"Number of settings: "<<settings.count()<<std::endl;

    settings.set("gosho", 12);
    settings.set("pesho", 31);
    settings.set(nullptr, 0);

    int value;
    std::cout<<"Operation successful? "<<settings.get("pesho", value)<<std::endl;
    std::cout<<"Value extracted: "<<value<<std::endl;

    int value2;
    std::cout<<"Operation successful? "<<settings.get("grisho", value2)<<std::endl;

    settings.set("pesho", value + 5);
    std::cout<<"Operation successful? "<<settings.get("pesho", value2)<<std::endl;
    std::cout<<"Value extracted: "<<value2<<std::endl;

    std::cout<<"Number of settings: "<<settings.count();

    return 0;
}
