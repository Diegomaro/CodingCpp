#pragma once
#include <iostream>
template <typename T>
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        bool insertHead(T data);
        bool insertTail(T data);
        bool insertNode(T data, int pos);
        bool removeHead();
        bool removeTail();
        bool removeNode(T data);
        int* getMiddle();
        bool printList();
        bool clear();
    private:
        class Node{
            public:
                Node *next;
                Node *prev;
                T data;
                Node();
            private:
        };
        Node* head;
        Node* tail;
};

#include "list.tpp"