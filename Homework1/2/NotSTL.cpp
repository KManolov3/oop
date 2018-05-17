#include "NotSTL.h"

int getLength(char* string){
    if(string == nullptr){
        std::cerr<<"Trying to get length of null pointer\n";
        return 0;
    }
    int len = 0;
    while(string[len] != 0)
        len++;

    return len;
}

void copyString(char* destination, char* source){
    if(destination == nullptr){
        std::cerr<<"Trying to copy into null pointer\n";
        return;
    }

    if(source == nullptr){
        std::cerr<<"Trying to copy from null pointer\n";
        return;
    }

    int i=0;

    do{
        destination[i] = source[i];
        i++;
    }while(source[i] != 0);
    destination[i] = '\0';
}

void printString(char* string){
    if(string == nullptr){
        std::cerr<<"Trying to print null pointer\n";
        return;
    }

    for(int i=0; i<getLength(string); i++){
        std::cout<<string[i];
    }
}

bool areStringsEqual(char* first, char* second){
    int lengthFirst = getLength(first), lengthSecond = getLength(second);
    if(lengthFirst != lengthSecond)
        return false;

    for(int i=0; i<lengthFirst; i++){
        if(first[i]!=second[i])
            return false;
    }

    return true;
}

char* inputUnspecifiedLengthString(){
    char *buffer = new char[10];
    int cap = 9;
    int curr = 0;
    char c;
    c=std::cin.peek();
    do{
        std::cin.get();
        buffer[curr++] = c;
        if(curr == cap)
        {
            char *temp = new char[cap+1];
            copyString(temp,buffer);
            buffer = new char[cap*2];
            cap *= 2;
            copyString(buffer,temp);
        }
    }while( (c=std::cin.peek())!= '\n');
    buffer[curr] = '\0';

    return buffer;
}
