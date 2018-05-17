#pragma once
#include <iostream>
#include <cstring>

template <class T>
class Pair{
public:
    Pair(const char* = "key", T const& = 0);
    Pair(Pair<T> const&);
    ~Pair();
    Pair<T>& operator=(Pair<T> const&);

    const char* getKey() const;
    const T& getValue() const;
    void setValue(T const&);

private:
    char* key;
    T value;

    void copy(Pair<T> const&);
    void erase();
};

template <class T>
Pair<T>::Pair(const char* name, T const& value):value(value){
    this->key = new char[strlen(name)+1];
    strcpy(this->key, name);
}

template <class T>
Pair<T>::Pair(Pair<T> const& other){
    copy(other);
}

template <class T>
Pair<T>::~Pair(){
    erase();
}

template <class T>
Pair<T>& Pair<T>::operator=(Pair<T> const& other){
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
void Pair<T>::copy(Pair<T> const& other){
    this->key = new char[strlen(other.key) + 1];
    strcpy(this->key, other.key);
    this->value = other.value;
}

template <class T>
void Pair<T>::erase(){
    delete[] key;
}
