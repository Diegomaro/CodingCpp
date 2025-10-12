#include "binaryTree.hpp"

int main(){
    BinaryTree btree;
    btree.insertNode(8);
    btree.printAll();
    btree.insertNode(4);
    btree.printAll();
    btree.insertNode(12);
    btree.printAll();
    btree.insertNode(2);
    btree.printAll(); 
    btree.insertNode(6);
    btree.printAll();
    btree.insertNode(10);
    btree.printAll();
    btree.insertNode(14);
    btree.printAll();
    btree.insertNode(1);
    btree.printAll();
    btree.insertNode(3);
    btree.printAll();
    btree.insertNode(5);
    btree.printAll();
    btree.insertNode(7);
    btree.printAll();
    btree.insertNode(9);
    btree.printAll();
    btree.searchNode(9);
    btree.clear();
    return 0;
}