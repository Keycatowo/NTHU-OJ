#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int Data;
    struct node* next;
    struct node* prev;
};
typedef struct node Node;

struct link_list{
    Node* head;
    Node* tail;
};
typedef struct link_list List;

Node* new_node(int data);
List* new_list();
bool is_list_empty(List *A);
void push(List *L,int data);
int pop(List* L);
