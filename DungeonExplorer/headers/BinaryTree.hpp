#include "Monster.hpp"

class BinaryTree{
public:
    class Node{
        public:
            Monster _data;
            Node *_left;
            Node* _right;
            Node();
            Node(Monster data);
        private:
    };
    BinaryTree();
    ~BinaryTree();
public:
    bool insertNode(Monster data);
    bool deleteNode(Monster data);
    bool searchNode(Monster data);
    bool isEmpty();
    bool printAll();
    bool clear();
private:
    Node* root;
    bool searchNodeExecution(Node* curNode, Monster data);
    void printAllExecution(Node* node, int curDepth);
    void clearExecute(Node *&node);
    bool findNodeToDelete(Node *&node, Monster data);
    void deleteNodeExecute(Node *&node);
    Node*& findMinNode(Node *&node);
};