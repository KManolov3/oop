#pragma once
#include <iostream>
#include <cstring>

template <class T>
class Pair{
public:
    Pair(const char* = "key", const T& = 0);
    Pair(const Pair<T>&);
    ~Pair();
    Pair<T>& operator=(const Pair<T>&);

    const char* getKey() const;
    const T& getValue() const;
    void setValue(T const&);

private:
    char* key;
    T value;

    void copy(const Pair<T>&);
    void erase();
};

template <class T>
Pair<T>::Pair(const char* key, const T& value):value(value){
    this->key = new char[strlen(key)+1];
    strcpy(this->key, key);
}

template <class T>
Pair<T>::Pair(const Pair<T>& other){
    copy(other);
}

template <class T>
Pair<T>::~Pair(){
    erase();
}

template <class T>
Pair<T>& Pair<T>::operator=(const Pair<T>& other){
    if(this!=&other){
        erase();
        copy(other);
    }
    return *this;
}

template <class T>
const char* Pair<T>::getKey() const{
    return key;
}

template <class T>
const T& Pair<T>::getValue() const{
    return value;
}

template <class T>
void Pair<T>::setValue(T const& value){
    this->value = value;
}

template <class T>
void Pair<T>::copy(const Pair<T>& other){
    this->key = new char[strlen(other.key) + 1];
    strcpy(this->key, other.key);
    this->value = other.value;
}

template <class T>
void Pair<T>::erase(){
    delete[] key;
}
