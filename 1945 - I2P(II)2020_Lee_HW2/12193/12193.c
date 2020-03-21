#include<stdio.h>
#define max(a,b) (a>b?a:b)
#define New(node) (node*)malloc(sizeof(node))

int input_list[10000];
int N;

typedef struct node{
    int data;
    int level;
    struct node* left ;
    struct node* right;
}Node;

Node* push(Node* root, int new_data,int l);
void build_tree(Node** root,int* a,int size);
void pre_order(Node* root);
void input();
void free_tree(Node* root);

int main(){
    freopen("input.txt","r",stdin);

    input();
    Node* root = NULL;
    build_tree(&root,input_list,N);
//    pre_order(root);
    free_tree(root);


    return 0;
}

Node* push(Node* root, int new_data,int l){
    if(root==NULL){
    /*if no tree*/
    /*build a tree*/
        root = (Node*)malloc(sizeof(Node));
        root->data = new_data;
        root->left = root->right = NULL;
        root->level = l;
        return root;
    }
    else{
    /*if already a tree*/
    /*recursive to build leaf*/
        if(new_data > root->data)
            // bigger, goes right
            root->right = push(root->right, new_data,l+1);
        else if(new_data < root->data)
            // smaller, goes left
            root->left = push(root->left, new_data,l+1);
        return root;
    }
}

void build_tree(Node** root,int* a,int size){
    Node* tmp = NULL;
    for(int i=0;i<size;i++)
        tmp = push(tmp,a[i],1);
    (*root) = tmp;
}

void pre_order(Node* root){
    if(root==NULL)
        return;
    printf("%d",root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void free_tree(Node* root){
    if(root==NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    printf("%d:%d\n",root->data,root->level);
    free(root);
}

void input(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&input_list[i]);
    }
}
