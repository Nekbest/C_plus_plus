#include <nahe.h>
void addToHead(Node*& head, int value){
 Node* newHead = new Node; newHead->value = value;
 newHead->next = head; head = newHead;
}
void addToNode(Node* &node, int value){
 Node* newNode = new Node; newNode->next = node->next;
 newNode->value = value; node->next = newNode;
}
void Print(Node* head){
 while (head->next != nullptr) {
  std::cout << head->value << '\t';  head = head->next;
 } std::cout << head->value << '\n';
}
Node* searchValue(Node* head, int value){
 while (head->value != value) {
  head = head->next; }
 if (head->next == nullptr) {
  std::cout << "node is not found\n"; }
 return head;}
