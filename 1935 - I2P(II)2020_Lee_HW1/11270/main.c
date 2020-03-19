#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void printList(Node *head);
void freeList(Node*);

int main() {
    freopen("input.txt","r",stdin);

	Node *head = NULL;
	Node *temp;
	int data;

    	head = createList();
	head = reverse(head);
	printList(head);
	freeList(head);
	return 0;
}



void freeList(Node *head)
{
	Node *temp;
	for(temp=head; temp!=NULL; temp=head)
	{
		head = head->next;
		free(temp);
	}
}

void printList(Node *head)
{
	Node *temp;
	for(temp = head; temp!=NULL; temp=temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}
