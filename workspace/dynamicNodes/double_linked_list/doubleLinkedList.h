#pragma once
#include <iostream>
#include "doubleLinkedNode.h"

template<typename T>
class LinkedList{
private:
        Node<T>* head =  nullptr;
        Node<T>* tail = nullptr;
        int size = 0;
    public:
        LinkedList();
        ~LinkedList();
        int length();  
        void add(const T& x);
        void add(int pos, const T& x);
        void addFirst(const T& x);
        void addLast(const T& x);
        void remove(const T& x);
        void set(int pos, const T& x);
        int get(int pos);
        int indexOf(const T& x);
        int lastIndexOf(const T& x);
        int getFirst();
        int getLast();
        bool contains(const T& x);
        void printAll();
        void clear();
};