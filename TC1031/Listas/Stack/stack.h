#pragma once
template <typename T>
class Stack {
    public:
        class Node {
            public:
                Node* next;
                T data;
                Node();
            private:
        };
    Stack();
    ~Stack();
    bool push(T data);
    bool pop();
    T* getTop();
    bool isEmpty();
    bool clear();
    bool printList();
    private:
        Node* head;
};

#include "stack.tpp"