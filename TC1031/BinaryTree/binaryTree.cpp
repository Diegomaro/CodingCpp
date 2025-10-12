#include "binaryTree.hpp"
#include <iostream>

BinaryTree::Node::Node(): _left(nullptr), _right(nullptr){};
BinaryTree::Node::Node(int data): _data(data), _left(nullptr), _right(nullptr){};

BinaryTree::BinaryTree(): root(nullptr) {};


BinaryTree::~BinaryTree(){
    
}

bool BinaryTree::insertNode(int data){
    Node* newNode = new(std::nothrow) Node(data);
    if(!newNode){
        return false;
    }
    if(!root){
        root = newNode;
        return true;
    }
    Node* tmp = root;

    while(tmp->_left || tmp->_right){
        if(tmp->_data > data) {
            if(tmp->_left){
                tmp = tmp->_left;
            } else{
                tmp->_left = newNode;
                return true;
            }
        }
        else if(tmp->_data < data) {
            if(tmp->_right){
                tmp = tmp->_right;
            } else{
                tmp->_right = newNode;
                return true;
            }
        }
        else {
            delete newNode;
            return false; //Nodo repetido
        }
    }
    if(data < tmp->_data){
        tmp->_left = newNode;
        return true;
    } else if (data > tmp->_data){
        tmp->_right = newNode;
        return true;
    }
    delete newNode;
    return false;
}

bool BinaryTree::insertNodeRecursively(int data){
    Node* newNode = new(std::nothrow) Node(data);
    if(!newNode){
        return false;
    }
    if(insertNodeRecExecution(root, newNode)){
        return true;
    } else{
        delete newNode;
        return false;
    }
}

bool BinaryTree::insertNodeRecExecution(Node *&curNode, Node *newNode){
    if(!curNode){
        curNode = newNode;
        return true;
    }
    if(curNode->_data > newNode->_data){
        return insertNodeRecExecution(curNode->_left, newNode);
    } else if(curNode->_data < newNode->_data){
        return insertNodeRecExecution(curNode->_right, newNode);
    }
    return false;
}

int *BinaryTree::searchNode(int data){
    return searchNodeExecution(root, data);
}

int *BinaryTree::searchNodeExecution(Node* node, int data){
    if(!node){
        return nullptr;
    }
    if(data < node->_data){
        searchNodeExecution(node->_left, data);
    } else if(data > node->_data){
        searchNodeExecution(node->_right, data);
    } else{
        return &node->_data;
    }
    return nullptr;
}

bool BinaryTree::isEmpty(){
    if(root) return false; 
    return true;
}

bool BinaryTree::clear(){
    if(!root) return false;   
    clearExecute(root);
    root = nullptr;
    return true;
}

void BinaryTree::clearExecute(Node *&curNode){
    if(curNode->_left){
        clearExecute(curNode->_left);
    }
    if(curNode->_right){
        clearExecute(curNode->_right);
    }
    if(!curNode->_left && !curNode->_right){
        delete curNode;
        curNode = nullptr; // asigna lastNode->_left o _right a nullptr
    }
}

bool BinaryTree::printAll(){
    if (!root) return false;
    std::cout << "arbol:" << std::endl;
    printAllExecution(root, 0);
    return true;
}

void BinaryTree::printAllExecution(Node* node, int curDepth){
    if(node->_left){
        printAllExecution(node->_left, curDepth + 1);
    }
     for(int i = 0; i < curDepth; i++){
            std::cout << "    ";
        }
    std::cout << node->_data << std::endl;
    if(node->_right){
        printAllExecution(node->_right, curDepth + 1);
    }
}