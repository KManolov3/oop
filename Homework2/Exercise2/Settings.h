#pragma once
#include <iostream>
#include <cstring>
#include "Pair.h"

template <class T>
class Settings{
public:
    Settings(size_t=10);
    Settings(Settings const&);
    ~Settings();
    Settings& operator=(Settings const&);

    size_t count() const;
    void set(const char*, const T&);
    bool get(const char*, T&) const;

private:
    Pair<T>* settings;
    size_t currentSettingSize;
    size_t maxSettingSize;

    int findElemIndex(const char*) const;
    void addSetting(const char*, const T&);
    void resize();
    void copy();
};

template <class T>
Settings<T>::Settings(size_t maxSettingSize):maxSettingSize(maxSettingSize){
    currentSettingSize = 0;
    settings = new Pair<T>[maxSettingSize];
}

template <class T>
Settings<T>::Settings(Settings const& other){
    copy(other);
}

template <class T>
Settings<T>::~Settings(){
    delete[] settings;
}

template <class T>
Settings<T>& Settings<T>::operator=(Settings<T> const& other){
    if(this!=&other){
        delete[] settings;
        copy(other);
    }

    return *this;
}

template <class T>
size_t Settings<T>::count() const{
    return currentSettingSize;
}

template <class T>
void Settings<T>::set(const char* key, T const& value){
    int index = findElemIndex(key);

    if(index!=-1){
        settings[index].setValue(value);
        return;
    }

    addSetting(key, value);
}

template <class T>
bool Settings<T>::get(const char* key, T& value) const{
    int index = findElemIndex(key);

    if(index == -1)
        return false;

    value = settings[index].getValue();
    return true;
}

template <class T>
int Settings<T>::findElemIndex(const char* key) const{
    for(int i=0; i<currentSettingSize; i++){
        if(strcmp(settings[i].getKey(), key) == 0){
            return i;
        }
    }

    return -1;
}

template <class T>
void Settings<T>::addSetting(const char* key, T const& value){
    Pair<T> newSetting(key, value);

    if(currentSettingSize == maxSettingSize)
        resize();

    settings[currentSettingSize++] = newSetting;
}

template <class T>
void Settings<T>::resize(){
    Pair<T> *holder = settings;
    settings = new Pair<T>[maxSettingSize*=2];

    for(int i=0; i<currentSettingSize; i++){
        settings[i] = holder[i];
    }

    delete[] holder;
}

