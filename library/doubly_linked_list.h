#pragma once
#include <iostream>
#include "library.h"

struct Node
{
	library data;
	Node* next = nullptr;
	Node* previos = nullptr;
};

void add_to_head(Node*& head, Node*& tail, library data);
void add_to_end(Node*& head, Node*& tail, library data);
void print_with_begin(Node* head);
void print_with_tail(Node* tail);
void delete_search_value(Node*& head, Node*& tail, int year);
Node* delete_head(Node*& head, Node*& tail);
void delete_tail(Node*& tail, Node*& list);
void delete_after_node(Node*& node);
void delete_year(Node*& head);
