#include <iostream>
#include "line.h"

Queue::Queue() 
{
	head = nullptr;
	tail = nullptr;
}


void Queue::enqueue(int value)
{
	if (is_empty())
	{
		tail = new Node;
		tail->value = value;
		head = tail;
	}
	else
	{
		head = head;
		tail->next = new Node;
		tail = tail->next;
		tail->value = value;
	}
}

void Queue::dequeue()
{
	Node* p = head;
	head = head->next;
	p->next = nullptr;
	delete p;
}

int Queue::peek()
{
	return head->value;
}

bool Queue::is_empty()
{
	return (!head);
}

void Queue::print()
{
	if (is_empty())
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

void Queue::clear()
{
	while (!is_empty())
		dequeue();
}
