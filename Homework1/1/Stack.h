#include <iostream>
#include "Node.h"

template <class T>
class LStack{
    Node<T>* topEl;

    public:
    LStack();
    LStack(LStack<T> const&);
    ~LStack();
    LStack& operator=(LStack<T> const&);

    T top() const;
    T pop();
    void push(T inf);

    bool isEmpty() const;

    private:
    void copy(Node<T>* toCopy);
    void erase();
    void copyStack(LStack<T> const&);
    void deleteStack();
};
