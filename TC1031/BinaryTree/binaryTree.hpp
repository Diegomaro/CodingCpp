#pragma once
#include <iostream>

class BinaryTree {
    public:
        class Node{
            public:
                int _data;
                Node *_left;
                Node* _right;
                Node();
                Node(int data);
            private:
        };
        BinaryTree();
        ~BinaryTree();
    public:
        bool insertNode(int data);
        bool insertNodeRecursively(int data);
        bool deleteNode(int data);
        bool searchNode(int data);
        bool isEmpty();
        bool printAll();
        bool clear();
    private:
        Node* root;
        bool searchNodeExecution(Node* curNode, int data);
        void printAllExecution(Node* node, int curDepth);
        bool insertNodeRecExecution(Node *&curNode, Node *newNode);
        void clearExecute(Node *&node);
        bool findNodeToDelete(Node *&node, int data);
        void deleteNodeExecute(Node *&node);
        Node*& findMinNode(Node *&node);
};