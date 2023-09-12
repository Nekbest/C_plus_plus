#include <iostream> 
struct Node 
{ 
 Node* next = nullptr; 
 int value = 0; 
}; 
 
void addToHead(Node* &head, int value); 
void addToNode(Node* &node, int value); 
void Print(Node* head); 
Node* searchValue(Node* head, int value);
