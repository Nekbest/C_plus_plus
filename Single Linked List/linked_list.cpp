#include "listheader.h"


void addToHead(Node*& head, int value)
{
	Node* newHead = new Node;
	newHead->value = value; newHead->next = head;
	head = newHead;
}


void addAfterNode(Node*& node, int value)
{
	Node* newNode = new Node;
	newNode->next = node->next; newNode->value = value;
	node->next = newNode;
}


bool isEmpty(Node* head)
{
	return (!head);
}


void Print(Node* head)
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
			if (current != nullptr)
			{
				std::cout << current->value << '\n';
				current = current->next;
			}
		}  
		std::cout << '\n';
	}
}


Node* searchValue(Node* head, int value)
{
	Node* current = head;
	Node* result = nullptr; while (current->next != nullptr && result == nullptr)
	{
		if (current->value == value)
		{
			result = current;
		}  current = current->next;
	} return result;
}


void deleteHead(Node*& head)
{
	Node* ptr = head; head = head->next;
	ptr->next = nullptr; delete ptr;
	ptr = nullptr;
}


void deleteAfterNode(Node*& node) 
{
	Node* ptr = node->next; node->next = ptr->next;
	ptr->next = nullptr; delete ptr;
	ptr = nullptr;
}
