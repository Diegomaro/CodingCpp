#include "list.h"

template <typename T>
LinkedList<T>::Node::Node(){
    next = nullptr;
    prev = nullptr;
}
template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    clear();
}

template <typename T>
bool LinkedList<T>::insertHead(T data){
    Node* newNode = new(std::nothrow) Node;
    if(!newNode){
        return false;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    if(head->next == nullptr){
        tail = head;
    }
    return true;
}

template <typename T>
bool LinkedList<T>::insertTail(T data){
    Node* newNode = new(std::nothrow) Node;
    if(!newNode){
        return false;
    }
    newNode->data = data;
    if(!tail){
        head = newNode;
        tail = newNode;
        return true;
    }
    tail->next = newNode;
    tail = newNode;
    return true;
}

template <typename T>
bool LinkedList<T>::insertNode(T data, int pos){
    if(!head){
        return false;
    }
    if(pos == 0){
        return insertHead(data);
    }
    Node* newNode = new(std::nothrow) Node;
    if(!newNode){
        return false;
    }
    newNode->data = data;
    int ctr = 0;
    Node* tmp = head;
    while(ctr != pos - 1 && tmp != nullptr){
        tmp = tmp->next;
        ctr++;
    }
    if(!tmp){
        return false;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    return true;
}

template <typename T>
bool LinkedList<T>::removeHead(){
    if(!head){
        return false;
    }
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        return true;
    }
    Node* tmp = head->next;
    delete head;
    head = tmp;
    return true;
}

template <typename T>
bool LinkedList<T>::removeTail(){
    if(!tail){
        return false;
    }
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        return true;
    }
    Node* tmp = head;
    while(tmp->next->next != nullptr){
        tmp = tmp->next;
    }
    delete tail;
    tail = tmp;
    tail->next = nullptr;
    return true;
}

template <typename T>
bool LinkedList<T>::removeNode(T data){
    if(!head){
        return false;
    }
    if(head->data == data){
        removeHead();
        return true;
    } else if(tail->data == data){
        removeTail();
        return true;
    } else if(head == tail){
        return false;
    }
    Node* tmp = head;
    while(tmp->next->data != data){
        tmp = tmp->next;
    }
    Node* tmp2 = tmp->next->next;
    delete tmp->next;
    tmp->next = tmp2;
    return true;
}


template <typename T>
int* LinkedList<T>::getMiddle(){
    return nullptr;
}

template <typename T>
bool LinkedList<T>::printList(){
    if(!head){
        return false;
    }
    Node* tmp = head;
    while(tmp){
        std::cout << tmp->data <<", ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
    return true;
}

template <typename T>
bool LinkedList<T>::clear(){
    if(!head){
        return false;
    }
    Node* tmp = head;
    while(tmp){
        tmp = tmp->next;
        delete head;
        head = tmp;
    }
    tail = nullptr;
    return true;
}