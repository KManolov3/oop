#include <iostream>
#include "ElectricNet.cpp"

int main(){
    ElectricDevice dev1("Gosho", 4), dev2, dev3(dev1);
    std::cout<<dev2.getName()<<std::endl;
    std::cout<<dev2.getPowerConsumed()<<std::endl;
    dev2 = dev3;
    dev1.setName("Pesho");
    dev3.setName("Velin");
    std::cout<<dev1.getName()<<std::endl;
    std::cout<<dev2.getName()<<std::endl;
    std::cout<<dev3.getName()<<std::endl;

    ElectricNet net, net2(12), net3(net);
    net3 = net2;

    std::cout<<"The max power consumption of the grid is: "<<net.getMaxConsumption()<<std::endl;
    std::cout<<"Adding some devices to the grid.\n";
    net+dev1;
    net+=dev2;
    net+dev3;
    ++net;
    net+dev3;
    ElectricDevice extractedDev = net["Gosho"];
    std::cout<<extractedDev.getName()<<" "<<extractedDev.getPowerConsumed()<<std::endl;
    ElectricDevice failed = net["Tisho"];
    std::cout<<failed.getName()<<" "<<failed.getPowerConsumed()<<std::endl;
    --net;
    net-dev3;
    --net;

    std::cout<<"Is there a device in the network? "<<!net<<std::endl;
    net-dev2;
    net-dev1;
    std::cout<<"Is there a device in the network? "<<!net<<std::endl;

    return 0;
}
