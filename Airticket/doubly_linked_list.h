#pragma once
#include <iostream>
#include "Airport.h"

struct Node
{
	Airport ticket;
	Node* next = nullptr;
	Node* previos = nullptr;
};

void add_to_head(Node*& head, Node*& tail, Airport ticket);
void add_to_end(Node*& head, Node*& tail, Airport ticket);
void print_with_begin(Node* head);
void print_with_tail(Node* tail);
void delete_search_value(Node*& head, Node*& tail, Date date);
Node* delete_head(Node*& head, Node*& tail);
void delete_tail(Node*& tail, Node*& list);
void delete_after_node(Node*& node);
