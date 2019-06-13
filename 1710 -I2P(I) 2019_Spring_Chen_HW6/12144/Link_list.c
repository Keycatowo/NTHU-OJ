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

Node* new_node(int data){
    Node *p;
    p = (Node*) malloc(sizeof(Node));
    p->Data = data;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

List* new_list(){
    List *l;
    l = (List*) malloc(sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    return l;
}


bool is_list_empty(List *A){
    if(A->head == NULL)
        return true;
    else
        return false;
}

void push(List *L,int data){
    if(is_list_empty(L))
    {
        L->head = L->tail = new_node(data);
        return;
    }
    else
    {
        L->tail->next = new_node(data);
        Node* tmp = L->tail;
        tmp->next->prev = tmp;
        L->tail = tmp->next;
    }
}

int pop(List* L){
    Node *tmp = L->head;
    int index = L->head->Data;
    if(L->head == L->tail)
    {
        L->head = L->tail = NULL;
    }
    else
    {
        L->head = L->head->next;
        L->head->prev = NULL;
    }
    free(tmp);
    return index;
}

