#pragma once

template <typename T>
struct Node{
    T data;
    Node* next;
    Node* last;
    Node(T d): data(d), next(nullptr), last(nullptr){}
};