#ifndef __FUNCTION_H__
#define __FUNCTION_H__
typedef struct _Node{
	long data;  //the value of coefficient
	int power; //the value of power
	struct _Node *next;
	struct _Node *prev;
}Node;
void printNode(Node* head);         //the function which will print the output
Node* create();                     //create polynomial linked list
void destroy(Node *node);           //destroy polynomial linked list
Node* multiple(Node* p1, Node* p2); //input two polynomial linked list and return the result
#endif
