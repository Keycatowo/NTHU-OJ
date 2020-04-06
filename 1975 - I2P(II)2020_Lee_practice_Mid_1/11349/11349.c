#include <stdio.h>
#include <stdlib.h>
#include "function.h"

#define ffor(k) for(int i=0;i<k;i++)
#define New(node) (node*)malloc(sizeof(node))
#define elif else if

Node* build_tree(Node* root, int new_data){
    if(root==NULL){
        root = New(Node);
        root->data = new_data;
        root->left = root->right = NULL;
    }
    else{
        if (new_data > root->data){
            root->right = build_tree(root->right,new_data);
        }
        else if(new_data < root->data){
            root->left = build_tree(root->left,new_data);
        }
    }
    return root;
}



void create_tree(Node** root, int n){
    int tmp_input;
    Node* Root = NULL;

    ffor(n){
        scanf("%d",&tmp_input);
        Root = build_tree(Root,tmp_input);
    }

    (*root) = Root;
}


void preorder_tree(Node* root){
    if (root==NULL)
        return;

    printf(" %d",root->data);
    preorder_tree(root->left);
    preorder_tree(root->right);
}

void inorder_tree(Node* root){
    if (root==NULL)
        return;

    inorder_tree(root->left);
    printf(" %d",root->data);
    inorder_tree(root->right);
}

void postorder_tree(Node* root){
    if (root==NULL)
        return;


    postorder_tree(root->left);
    postorder_tree(root->right);
    printf(" %d",root->data);
}


void print_tree(Node* root){
    printf("preorder:");
    preorder_tree(root);
    printf("\n");

    printf("inorder:");
    inorder_tree(root);
    printf("\n");

    printf("postorder:");
    postorder_tree(root);
    printf("\n");
}






