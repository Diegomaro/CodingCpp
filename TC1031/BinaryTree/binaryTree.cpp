#include "binaryTree.hpp"

BinaryTree::Node::Node(): _left(nullptr), _right(nullptr){};
BinaryTree::Node::Node(int data): _data(data), _left(nullptr), _right(nullptr){};

BinaryTree::BinaryTree(): root(nullptr) {};

BinaryTree::~BinaryTree(){
    clear();
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

bool BinaryTree::deleteNode(int data){
    return findNodeToDelete(root, data);
}

bool BinaryTree::findNodeToDelete(Node *&node, int data){
    if(!node) return false;
    if(node->_data < data) {
        return findNodeToDelete(node->_right, data);
    } else if(node->_data > data) {
        return findNodeToDelete(node->_left, data);
    } else{
        deleteNodeExecute(node);
        return true;
    }
    return false;
}

void BinaryTree::deleteNodeExecute(Node *&node){
    if(!node->_left && !node->_right){
        delete node;
        node = nullptr;
        return;
    }
    if(!node->_left){
        Node* tmp = node->_right;
        delete node;
        node = tmp;
        return;
    }
    if(!node->_right){
        Node* tmp = node->_left;
        delete node;
        node = tmp;
        return;
    }
    Node *&tmpNode = findMinNode(node->_right);
    if(!tmpNode->_right){
        node->_data = tmpNode->_data;
        delete tmpNode;
        tmpNode = nullptr;
        return;
    }
    node->_data = tmpNode->_data;
    Node* tmpSon = tmpNode->_right;
    delete tmpNode;
    tmpNode = tmpSon;
    return;
}

BinaryTree::Node *&BinaryTree::findMinNode(Node *&node){
    if(node->_left){
        return findMinNode(node->_left);
    }
    return node;
}

bool BinaryTree::searchNode(int data){
    return searchNodeExecution(root, data);
}

bool BinaryTree::searchNodeExecution(Node* node, int data){
    if(!node){
        return false;
    }
    if(data < node->_data){
        return searchNodeExecution(node->_left, data);
    } else if(data > node->_data){
        return searchNodeExecution(node->_right, data);
    } 
    return true;
}

bool BinaryTree::isEmpty(){
    if(root) return false; 
    return true;
}

bool BinaryTree::clear(){
    if(!root) return false;   
    clearExecute(root);
    return true;
}

void BinaryTree::clearExecute(Node *&curNode){
    if(curNode->_left){
        clearExecute(curNode->_left);
    }
    if(curNode->_right){
        clearExecute(curNode->_right);
    }
    delete curNode;
    curNode = nullptr; // asigna lastNode->_left o _right a nullptr
    
}

bool BinaryTree::printAll(){
    if (!root) return false;
    std::cout << "arbol:" << std::endl;
    printAllExecution(root, 0);
    return true;
}

void BinaryTree::printAllExecution(Node* node, int curDepth){
    if(node->_right){
        printAllExecution(node->_right, curDepth + 1);
    }
     for(int i = 0; i < curDepth; i++){
            std::cout << "    ";
        }
    std::cout << node->_data << std::endl;
    if(node->_left){
        printAllExecution(node->_left, curDepth + 1);
    }
}