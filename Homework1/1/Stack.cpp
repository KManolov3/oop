#include "Stack.h"

template <class T>
LStack<T>::LStack(){
    topEl = nullptr;
}

template <class T>
LStack<T>::LStack(LStack<T> const& other){
    copyStack(other);
}

template <class T>
LStack<T>::~LStack(){
    deleteStack();
}

template <class T>
LStack<T>& LStack<T>::operator=(LStack<T> const& other){
    if(this!=other){
        deleteStack();
        copyStack(other);
    }
    return *this;
}

template <class T>
void LStack<T>::copyStack(LStack<T> const& other){
    copy(other.top);
}

template <class T>
void LStack<T>::copy(Node<T>* toCopy){
    if(toCopy){
        push(toCopy->inf);
        copy(toCopy->next);
    }
}

template <class T>
void LStack<T>::push(T inf){
    Node<T>* newNode = new Node<T>;
    newNode->inf = inf;
    newNode->next = topEl;
    topEl = newNode;
}

template <class T>
void LStack<T>::deleteStack(){
    while(!isEmpty())
        pop();
}

template <class T>
T LStack<T>::pop(){
    if(!isEmpty()){
        Node<T>* toDelete = topEl;
        T inf = topEl->inf;
        topEl = topEl->next;
        delete toDelete;
        return inf;
    }
    return 0;
}

template <class T>
T LStack<T>::top() const{
    return topEl->inf;
}

template <class T>
bool LStack<T>::isEmpty() const{
    return topEl == nullptr;
}


