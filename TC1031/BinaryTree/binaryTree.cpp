#include "binaryTree.hpp"
#include <iostream>

BinaryTree::Node::Node(): _left(nullptr), _right(nullptr){};
BinaryTree::Node::Node(int data): _data(data), _left(nullptr), _right(nullptr){};

BinaryTree::BinaryTree(): root(nullptr), depth(0) {};


BinaryTree::~BinaryTree(){
    
}

bool BinaryTree::insertNode(int data){
    Node* newNode = new(std::nothrow) Node();
    if(!newNode){
        return false;
    }
    newNode->_data = data;
    if(!root){
        root = newNode;
        depth = 0;
        return true;
    }
    Node* tmp = root;
    int curDepth = 1;

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
        else return false; //Nodo repetido
        curDepth++;
    }
    if(data < tmp->_data){
        tmp->_left = newNode;
        return true;
    } else if (data > tmp->_data){
        tmp->_right = newNode;
        return true;
    }
    return false;
}

bool BinaryTree::printAll(){
    if (!root) return false;
    /*
    for non recursive method
    int separation = 1;
    for(int i = 0; i < depth-1; i++){
        separation *=2;
    }
    */
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