#include "stack.h"
#include <iostream>

template <typename T>
Stack<T>::Node::Node(){
    next = nullptr;
}
template <typename T>
Stack<T>::Stack(){
    head = nullptr;
}

template <typename T>
Stack<T>::~Stack(){
    clear();
}

template <typename T>
bool Stack<T>::push(T data){
    Node* newNode = nullptr;
    newNode = new(std::nothrow) Node;
    if(!newNode){
        return false;
    }
    newNode->data = data;
    if(!head){ 
        head = newNode;
        return true;
    }
    newNode->next = head;
    head = newNode;
    return true;
}

template <typename T>
bool Stack<T>::pop(){
    if(!head){
        return false;
    }
    Node* newHead = head->next;
    delete head;
    head = newHead;
    return true;
}

template <typename T>
T* Stack<T>::getTop(){
    if(!head){
        return nullptr;
    }
    return &head->data;
}

template <typename T>
bool Stack<T>::isEmpty(){
    if(head){
        return false;
    }
    return true;
}

template <typename T>
bool Stack<T>::clear(){
    if(!head){
        return false;
    }
    Node* temp = head;
    while(temp){
        temp = temp->next;
        delete head;
        head = temp;
    }
    return true;
}

template <typename T>
bool Stack<T>::printList(){
    if(!head){
        return false;
    }
    Node* temp = head;
    while(temp){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    return true;
}