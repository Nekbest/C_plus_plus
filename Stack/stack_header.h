#pragma once
#include <iostream>

class AStack
{
	int size;
	int top;
	int* stack;
public:
	AStack(const int maxsize);
	~AStack();
	void push(int element);
	void pop();
	void print();
	bool isEmpty();
};
