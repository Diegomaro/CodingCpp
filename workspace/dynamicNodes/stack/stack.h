#pragma once
#include <iostream>
#include "node.h"

template<typename T>
class Stack{
private:
    Node<T>* _head =  nullptr;
public:
    Stack();
    ~Stack();
    void push(const T& x);
    void pop();
    int peek();
    int search(const T& x);
    bool empty();
    void clear();
};