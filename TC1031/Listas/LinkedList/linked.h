#pragma once

template <typename T>
class LinkedList {
public:
	class Node {
		public:
			T data;
			Node *next;

			Node();
	};

	LinkedList();
	~LinkedList();
	bool insertHead(T data);
	bool insertTail(T data);
	bool deleteHead();
	bool deleteTail();
	bool deleteNode(T data);
	bool printAll();
	bool clear();
private:
	Node *head;
	Node *tail;
};
#include "linked.tpp"