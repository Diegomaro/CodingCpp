#include "linked.h"
#include <iostream>

template <typename T>
LinkedList<T>::Node::Node() {
	next = nullptr;
}
template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	clear();
}

template <typename T>
bool LinkedList<T>::insertHead(T data) {
	Node *newNode = nullptr;

	newNode = new(std::nothrow) Node;
	if(!newNode)
		return false;

	newNode->data = data;
	newNode->next = head;

	head = newNode;
	if(!head->next){
		tail = head;
	}

	return true;
}

template <typename T>
bool LinkedList<T>::insertTail(T data){
	Node* newNode = nullptr; 
	newNode = new(std::nothrow) Node;
	if(!newNode) return false;
	newNode->data = data;
	
	if(!head){
		head = newNode;
		tail = head;
		return true;
	}
	tail->next = newNode;
	tail = newNode;
    return true;
}

template <typename T>
bool LinkedList<T>::deleteHead(){
	if(!head){
		return false;
	}
	if(head == tail){
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;	
	}
	Node* temp = head->next;
	delete head;
	head = temp;
	return true;
}

template <typename T>
bool LinkedList<T>::deleteTail(){
	if(!tail){
		return false;
	}
	if(head==tail){
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;
	}

	Node* temp = head;
	while(temp->next->next != nullptr){
        temp = temp->next;
    }
	delete tail;
	tail = temp;
	tail->next = nullptr;
	return true;
}

template <typename T>
bool LinkedList<T>::deleteNode(T data){
	if(!head){
		return false;
	}
	if((head==tail) && (head->data == data)){
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	Node* tmp = head;
	if(head->data == data){
		tmp = tmp->next;
		delete head;
		head = tmp;
		return true;
	}
	while(tmp->next != nullptr){
		if(tmp->next->data == data){
			Node* anchorNode = tmp->next->next;
			delete tmp->next;
			tmp->next = anchorNode;
			if(anchorNode == nullptr){
				tail = tmp;
			}
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

template <typename T>
bool LinkedList<T>::printAll(){
	if(!head){
		return false;
	}
    Node* index = nullptr;
	index = head; 
	std::cout << "lista:" << std::endl;
    while(index != nullptr){
        std::cout << index->data << ", ";
        index = index->next;
    }
	std::cout << "\nfin de la lista." << std::endl;
	return true;
}

template <typename T>
bool LinkedList<T>::clear(){
	if(!head){
		return false;
	}
	Node* index = head;

	while(index != nullptr){
		index = index->next;
		delete head;
		head = index;
	}
	tail = nullptr;
	return true;
}