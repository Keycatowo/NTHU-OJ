#ifndef __FUNCTION_H__
#define __FUNCTION_H__

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* createList();
Node* reverse(Node*);

#endif

