#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define FILE_MODE 1
#define DEBUG_MODE 0
#define MAX_N 100005
#define MAX_STR 300005
#define New(node) (node*)malloc(sizeof(node))
#define New0(node) (node*)calloc(1,sizeof(node))
#define ffor(k) for(int i=0;i<k;i++)
#define show(a) (DEBUG_MODE)?printf("%s:%d\n",#a,a):1
#define LOGGING(s) (DEBUG_MODE)?printf("logs:\t%s\n",s):1

typedef enum {AND,OR,ID}NodeType;


typedef struct _node{
    NodeType type;
    int id;
    bool value;
    struct _node* parent;
    struct _node* left;
    struct _node* right;
}Node;

Node** node_list;// a list to store node pointer (not store node)

void construct_tree(Node** root);
void flip(Node* curNode);
void free_tree(Node* root);



int main(){
    (FILE_MODE)?freopen("12183_input.txt","r",stdin):1;

    int T,N,M;
    scanf("%d",&T);
    show(T);
    while(T--){
        scanf("%d %d\n",&N,&M);
        show(N);show(M);
        node_list = (Node**)malloc((N+1)*sizeof(Node*));//+1 because without 0
        Node* root = NULL;

        construct_tree(&root);
        LOGGING("Built tree");
        root->parent=NULL;
        ffor(M){
            LOGGING("Operation");
            int target;



            scanf("%d",&target);
            show(target);
            flip(node_list[target]);
            printf("%d\n",root->value);
        }

        free_tree(root);
        free(node_list);
    }
    return 0;
}

void construct_tree(Node** root){
    char input = getchar();

    switch (input){
        case '\n':
            LOGGING("Finish one line");
            return;
        case '&':
        case '|':
            /// build node for OP
            (*root) = New0(Node);
            (*root)->type = (input=='&')?AND:OR;
            // build left subtree
            construct_tree(&(*root)->left);
            (*root)->left->parent = (*root);
            // build right subtree
            construct_tree(&(*root)->right);
            (*root)->right->parent = (*root);
            // init value
            (*root)->value = false;
            break;
        case '[':
            /// build node for ID
            (*root) = New0(Node);
            (*root)->type = ID;
            scanf("%d]",&(*root)->id); show((*root)->id);
            node_list[(*root)->id] = (*root); // throw the node into list
            // init value
            (*root)->left = NULL;
            (*root)->right = NULL;
            (*root)->value = false;
            break;
    }


}


void free_tree(Node* root){
    if(root==NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void flip(Node* curNode){
    curNode->value = !curNode->value;
    if(curNode->parent==NULL) return;

    switch(curNode->parent->type){
        case AND:
            if (curNode->parent->value ^
                (curNode->parent->left->value & curNode->parent->right->value))
                    return flip(curNode->parent);
            break;
        case OR:
            if (curNode->parent->value ^
                (curNode->parent->left->value | curNode->parent->right->value))
                    return flip(curNode->parent);
            break;

    }
}
