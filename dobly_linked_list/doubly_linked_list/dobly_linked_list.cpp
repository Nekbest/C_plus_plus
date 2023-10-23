#include "doubly_linked_list.h"



void addToHead(Node*& head, Node*& tail, int value)
{
	Node* newHead = new Node;
	newHead->value = value; newHead->next = head;
	newHead->previos = nullptr;
	head = newHead;
	if (head->next == nullptr)
		tail = head;
	else
	{
		Node* current = &(*tail);
		while (current->previos != nullptr)
			current = current->previos;
		current->previos = head;
	}
}


void addToEnd(Node*& head, Node*& tail, int value)
{
	Node* current = &(*head);
	while (current->next != nullptr)
		current = current->next;
	current->next = new Node;
	current->next->value = value;
	current->next->previos = current;
	tail = current->next;
}


bool isEmpty(Node* head)
{
	return (!head);
}


void Print_with_begin(Node* head)
{
	if (isEmpty(head))
	{
		std::cout << "nullptr\n";
	}
	else
	{
		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->value << "\n";
			current = current->next;
		}
	}
}


void Print_with_tail(Node* tail)
{
	if (isEmpty(tail))
	{
		std::cout << "nullptr\n";
	}
	else
	{
		Node* current = tail;
		while (current != nullptr)
		{
			std::cout << current->value << "\n";
			current = current->previos;
		}
	}
}





Node* searchValue(Node* head, int value)
{
	Node* current = head;
	Node* result = nullptr; 
	while (current->next != nullptr && result == nullptr)
	{
		if (current->value == value)
		{
			result = current;
		}  current = current->next;
	} return result;
}


void deleteHead(Node*& head, Node*& tail)
{
	Node* ptr = head;
	head = head->next;
	head->previos = nullptr;
}


void deleteTail(Node*& tail, Node*& head)
{
	Node* ptr = tail;
	tail = tail->previos;
	tail->next = nullptr;
}


void deleteAfterNode(Node*& node)
{
	Node* ptr = node->next; node->next = ptr->next;
	ptr->next = nullptr; delete ptr;
	ptr = nullptr;
}
