#ifndef __FUNCTION_H__
#define __FUNCTION_H__

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void create_tree(Node **root, int n);
void print_tree(Node *root);
void destroyTree(Node *root);

#endif
