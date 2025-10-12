#pragma once
#include "stack.h"

template <typename T>
Stack<T>::Stack() = default;

template <typename T>
Stack<T>::~Stack(){
     clear(); 
}

template <typename T>
void Stack<T>::push(const T& x){
    Node<T>* newNode = new Node{x};
    if(_head){
        newNode->next = _head;
        _head = newNode;
    } else{
        _head = newNode;
    }
}

template <typename T>
void Stack<T>::pop(){ 
    if(_head){
        Node<T>* newNode = _head;
        _head = _head->next;
        delete newNode;
    }
}

template <typename T>
int Stack<T>::peek(){ 
    if(_head){
        return _head->data;
    } else{
        return -1;
    }
}

template <typename T>
int Stack<T>::search(const T& x){ 
    if(_head){
        Node<T>* index = _head;
        int counter = 0;
        while(index != nullptr){
            if(index->data == x){
                return counter;
            }
            counter++;
            index = index->next;
        }
        return -1;
        return _head->data;
    } else{
        return -1;
    }
}

template <typename T>
bool Stack<T>::empty() {
    if(_head){
        return false;
    } else{
        return true;
    }
}

template <typename T>
void Stack<T>::clear() {
    Node<T>* index = _head;
    while (index != nullptr) {
        Node<T>* nxt = index->next;
        delete index;
        index = nxt;
    }
    _head = nullptr;
}