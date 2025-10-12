#include "queue.h"
#include <iostream>
template <typename T>
Queue<T>::Node::Node() {
	next = nullptr;
}

template <typename T>
Queue<T>::Queue(){
    head = nullptr;
    tail = nullptr;
}

template <typename T>
Queue<T>::~Queue(){
    clear();
}

template <typename T>
bool Queue<T>::enqueue(T data){
    Node* newNode = new(std::nothrow) Node;
    if(!newNode){
        return false;
    }
    newNode -> data = data;
    if(!head){
        head = newNode;
        tail = newNode;
        return true;
    }
    tail->next = newNode;
    tail = newNode;
    return true;
}

template <typename T>
bool Queue<T>::dequeue(){
    if(!head){
        return false;
    }
    if(head==tail){
        delete head;
        head = nullptr;
        tail =nullptr;
        return true;
    }
    Node* newHead = head->next;
    delete head;
    head = newHead;
    return true;
}

template <typename T>
int* Queue<T>::getFront(){
    return &head->data;
}

template <typename T>
bool Queue<T>::isEmpty(){
    if(!head){
        return true;
    }
    return false;
}

template <typename T>
bool Queue<T>::printAll(){
    if(!head){
        return false;
    }
    Node* temp = head;
    std::cout << "inicio: ";
    while(temp){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "fin." <<std::endl;
    return true;
}

template <typename T>
bool Queue<T>::clear(){
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