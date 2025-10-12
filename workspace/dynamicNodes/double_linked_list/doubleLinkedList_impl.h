#pragma once
#include "doubleLinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() = default;

template <typename T>
LinkedList<T>::~LinkedList(){
     clear(); 
}

template <typename T>
int LinkedList<T>::length(){
    return size;
}

template <typename T>
void LinkedList<T>::add(const T& x){
    size++;
    Node<T>* newNode = new Node{x};
    if (head == nullptr) {
        head = newNode;
        tail = head;
        return;
    }
    tail->next = newNode;
    newNode->last = tail;
    tail = newNode;
}

template <typename T>
void LinkedList<T>::add(int pos, const T& x){
    size++;
    Node<T>* newNode = new Node{x};
    if (head == nullptr) {
        head = newNode;
        tail = head;
        return;
    }
    if(pos<0){
        size--;
        addFirst(x);
        return;
    }

    Node<T>* index = head;
    int counter = 0;
    while(index != nullptr && counter <= pos){
        if(pos==counter){
            Node<T>* lastNode = index->last;
            Node<T>* nextNode = index;
            if(head==index){
                newNode->next = head;
                head->last = newNode;
                head = newNode;
            } else if(tail==index){
                newNode->next = tail;
                newNode->last = lastNode;
                lastNode->next = newNode;
                tail->last = newNode;
            } else{
                newNode->last = lastNode;
                lastNode->next = newNode;
                nextNode->last = newNode;
                newNode->next = nextNode;
            }
            return;
        }
        counter++;
        index = index->next;
    }
    tail->next = newNode;
    newNode->last = tail;
    tail = newNode;
}

template <typename T>
void LinkedList<T>::addFirst(const T& x){
    size++;
    Node<T>* newHead = new Node{x};  
    if(head){
        newHead->next = head;
        head->last = newHead;
        head = newHead;
    } else{
        head = newHead;
        tail = head;

    }
}

template <typename T>
void LinkedList<T>::addLast(const T& x){
    size++;
    Node<T>* newNode = new Node{x}; 
    if(head != nullptr){
        tail->next = newNode;
        newNode->last = tail;
        tail = newNode;
    } else{
        head = newNode;
        tail = head;
        return;
    }
}

template <typename T>
void LinkedList<T>::remove(const T& x){
    if(head==nullptr){
        return;
    }
    size--;
    Node<T>* index = head;
    while(index != nullptr){
        if(index->data == x){
            Node<T>* lastNode = index->last;
            Node<T>* nextNode = index->next;
            if(lastNode!=nullptr){
                lastNode->next = nextNode;
            } else{
                head = nextNode;
            }
            if(nextNode!=nullptr){
                nextNode->last = lastNode;
            } else{
                tail = lastNode;
            }
            delete index;
            return;
            
        } else{
            index = index->next;
        }
    }
    size++;
}

template <typename T>
void LinkedList<T>::set(int pos, const T& x){
    if (head == nullptr) {
        return;
    } else if(pos<0){
        return;
    }
    Node<T>* index = head;
    int counter = 0;
    while(index != nullptr && counter <= pos){
        if(pos==counter){
            index->data = x;
            return;
        }
        counter++;
        index = index->next;
    }
}

template <typename T>
int LinkedList<T>::get(int pos){
    if(pos<0) return -1;
    Node<T>* index = head;
    int counter = 0;
    while(index != nullptr){
        if(counter == pos){
            return index->data;
        }
        counter++;
        index = index->next;
    }
    return -1;
}

template <typename T>
int LinkedList<T>::indexOf(const T& x){
    if (head == nullptr) {
        return -1;
    }
        Node<T>* index = head;
        int counter = 0;
        while(index != nullptr){
            if(index->data == x){
                return counter;
            }
            counter++;
            index = index->next;
        }
        return -1;
}

template <typename T>
int LinkedList<T>::lastIndexOf(const T& x){
    if (head == nullptr) {
        return -1;
    }
        Node<T>* index = tail;
        int counter = length()-1;
        while(index != nullptr){
            if(index->data == x){
                return counter;
            }
            counter--;
            index = index->last;
        }
        return -1;
}

template <typename T>
int LinkedList<T>::getFirst(){
    if(head){
        return head->data;
    } else return -1;
    
}

template <typename T>
int LinkedList<T>::getLast(){
    if(tail){
        return tail->data;
    } else return -1;
}

template <typename T>
bool LinkedList<T>::contains(const T& x){
    Node<T>* index = head;
    while(index != nullptr){
        if(index->data == x){
            return true;
        }
        index = index->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::printAll(){
    Node<T>* index = head;
    while(index != nullptr){
        std::cout << index->data << std::endl;
        index = index->next;
    }
}

template <typename T>
void LinkedList<T>::clear() {
    size = 0;
    Node<T>* index = head;
    while (index != nullptr) {
        Node<T>* nxt = index->next;
        delete index;
        index = nxt;
    }
    head = nullptr;
    tail = nullptr;

}