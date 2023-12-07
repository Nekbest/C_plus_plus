#include "doubly_linked_list.h"


void add_to_head(Node*& head, Node*& tail, Airport ticket)
{
	Node* newHead = new Node;
	newHead->ticket = ticket;
	newHead->next = head;
	if (head != nullptr)
		head->previos = newHead;
	head = newHead;
	if (head->next == nullptr)
		tail = head;
}



void add_to_end(Node*& head, Node*& tail, Airport ticket)
{
	Node* current = head;
	while (current->next != nullptr)
		current = current->next;
	current->next = new Node;
	current->next->ticket = ticket;
	current->next->previos = current;
	tail = current->next;
}


bool is_empty(Node* head)
{
	return (!head);
}


void print_with_begin(Node* head)
{
	if (is_empty(head))
	{
		std::cout << "nullptr\n";
	}
	else
	{
		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->ticket.destination << " " << current->ticket.flight_number << " " <<
				current->ticket.aircraft_model << " " << current->ticket.full_name << " " <<
				current->ticket.date.day << " " << current->ticket.date.month << " " << current->ticket.date.year << "\n";
			current = current->next;
		}
	}
}


void print_with_tail(Node* tail)
{
	if (is_empty(tail))
	{
		std::cout << "nullptr\n";
	}
	else
	{
		Node* current = tail;
		while (current != nullptr)
		{
			std::cout << current->ticket.destination << " " << current->ticket.flight_number << " " <<
				current->ticket.aircraft_model << " " << current->ticket.full_name << " " <<
				current->ticket.date.day << " " << current->ticket.date.month << " " << current->ticket.date.year << "\n";
			current = current->previos;
		}
	}
}


void delete_search_value(Node*& head, Node*& tail, Date date)
{
	Node* current = head;
	Node* update;

	while (current->next != nullptr)
	{
		while (current->previos == nullptr && current->ticket.date < date)
		{
			current = head = delete_head(current, tail);
		}
		if (tail->ticket.date < date)
		{
			delete_tail(tail, current);
		}

		else if (current->previos != nullptr && current->ticket.date < date)
		{
			update = current;
			current = current->previos;
			current->next = update->next;
			current = current->next;
			current->previos = update->previos;
			delete update;
		}
		else
			current = current->next;
	}
}


Node* delete_head(Node*& head, Node*& tail)
{
	if (head->next != nullptr)
	{
		head = head->next;
		delete head->previos;
		head->previos = nullptr;
	}
	else
	{
		head = nullptr;
		tail = nullptr;
	}
	return head;
}


void delete_tail(Node*& tail, Node*& head)
{
	if (tail->previos != nullptr)
	{
		tail = tail->previos;
		delete tail->next;
		tail->next = nullptr;
	}
	else
	{
		head = nullptr;
		tail = nullptr;
	}
}


void delete_after_node(Node*& node)
{
	Node* ptr = node->next; node->next = ptr->next;
	ptr->next = nullptr; delete ptr;
	ptr = nullptr;
}
