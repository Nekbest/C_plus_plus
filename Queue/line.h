#pragma once
#include <iostream> 

class Queue {
	struct Node
	{
		int value = 0;
		Node* next = nullptr;
	};
	Node* head;
	Node* tail;
public:
	Queue();
	void enqueue(int value);
	void dequeue();
	bool is_empty();
	int peek();
	void print();
	void clear();
};
