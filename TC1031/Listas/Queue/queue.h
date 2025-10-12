#pragma once

template <typename T>
class Queue{
    public:
        class Node{
            public:
                Node* next;
                T data;
                Node();
            private:
        };
        Queue();
        ~Queue();
        bool enqueue(T data);
        bool dequeue();
        int* getFront();
        bool isEmpty();
        bool printAll();
        bool clear();
    private:
        Node* head;
        Node* tail;
};

#include "queue.tpp"