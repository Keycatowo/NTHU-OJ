#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b?a:b)
#define New(node) (node*)malloc(sizeof(node))
#define MAX 10000


int input_list[MAX];
int N,max_level=0;
int level_sum[MAX];
int level_count[MAX];

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
void preprocess(Node* root);
void operation(Node* root);


int main(){
    freopen("input.txt","r",stdin);

    input();
    Node* root = NULL;
    build_tree(&root,input_list,N);
    for(int i =0;i<N;i++){
        level_sum[i]=level_count[i]=0;
    }
    max_level = 0;

    preprocess(root);
    operation(root);
    free_tree(root);


    return 0;
}

void build_tree(Node** root,int* a,int size){
    Node* tmp = NULL;
    for(int i=0;i<size;i++)
        tmp = push(tmp,a[i],1);
    (*root) = tmp;
}

Node* push(Node* root, int new_data,int l){
    if(root==NULL){
    /*if no tree*/
    /*build a tree*/
        root = New(Node);
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



void in_order(Node* root){
    if(root==NULL)
        return;
    in_order(root->left);
    printf("%d ",root->data);
    in_order(root->right);
}

void free_tree(Node* root){
    if(root==NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
//    printf("%d:%d\n",root->data,root->level);
    free(root);
}

void input(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&input_list[i]);
    }
}

void preprocess(Node* root){
    if(root==NULL)
        return;
    preprocess(root->left);
    preprocess(root->right);
//    printf("%d:%d\n",root->data,root->level);
    level_count[root->level]++;
    level_sum[root->level] += root->data;
    max_level = max(max_level,root->level);
}

void operation(Node* root){
    char mode[20];
    int n,m;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%s", mode);

        if(strcmp(mode,"P")==0){
            in_order(root);
            if(root==NULL)
                printf("NULL");
            printf("\n");
        }

        if(strcmp(mode,"GetMax")==0){
            printf("%d\n",max_level);
        }

        if(strcmp(mode,"SumLevel")==0){
            scanf("%d",&m);
            if(m>max_level)
                printf("0\n");
            else
                printf("%d\n",level_sum[m]);
        }

        if(strcmp(mode,"AverLevel")==0){
            scanf("%d",&m);
            if(m>max_level)
                printf("0\n");
            else
                printf("%.3f\n",(float)level_sum[m]/level_count[m]);
        }

    }

}
