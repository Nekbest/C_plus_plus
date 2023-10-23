#pragma once
#include <iostream>

struct Node
{
	int value = 0;
	Node* next = nullptr;
	Node* previos = nullptr;
};

void addToHead(Node*& head, Node*& tail, int value);
void addToEnd(Node*& head, Node*& tail, int value);
void Print_with_begin(Node* head);
void Print_with_tail(Node* tail);
Node* searchValue(Node* head, int value);
void deleteHead(Node*& head, Node*& tail);
void deleteTail(Node*& tail, Node*& list);
void deleteAfterNode(Node*& node);
