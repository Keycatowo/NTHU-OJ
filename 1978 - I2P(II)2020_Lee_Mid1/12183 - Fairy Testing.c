#include <stdio.h>
#include <stdbool.h>
#define FILE_MODE 0
#define DEBUG_MODE 0
#define MAX 100005
#define New0(node) (node*)calloc(1,sizeof(node))
#define New(node) (node*)malloc(sizeof(node))
#define LOGGING(s) (DEBUG_MODE)?printf("%s",s):1
#define show_int(a) (DEBUG_MODE)?printf("%s:%d\n",#a,a):1
#define show_char(a) (DEBUG_MODE)?printf("%s:%c\n",#a,a):1


typedef enum {OP_AND,OP_OR,ID}NodeType;

typedef struct node{

    bool value;
    int id;

    NodeType type;

    struct node *left;

    struct node *right;

    struct node *parent;

}Node;

Node** Node_list;

void construct_tree(Node** root){
    LOGGING("Construct tree\n");
    char input = getchar();
    show_char(input);
    switch (input){
        case '\n':
            return;
        case '|':
        case '&':
            // build node for OP
            LOGGING("OP\n");
            (*root) = New0(Node);
            (*root)->type = (input=='|')?OP_OR:OP_AND;
            (*root)->value = false;
            // build node for left
            LOGGING("\tBuild left\n");
            construct_tree(&(*root)->left);
            (*root)->left->parent = (*root);
            // build node for right
            LOGGING("\tBuild right\n");
            construct_tree(&(*root)->right);
            (*root)->right->parent = (*root);
            break;
        case '[':
            LOGGING("ID\n");
            (*root) = New0(Node);
            (*root)->type = ID;
            int id;
            scanf("%d]",&id);
            (*root)->id = id;
            show_int(id);
//            show_int((*root)->id);
            Node_list[(*root)->id] = (*root);
            (*root)->value = false;
            break;


    }


}

void free_tree(Node* root){
    if (root==NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void flip(Node* cur){
    cur->value = !cur->value;
    if(cur->parent==NULL) return;
    LOGGING("Flip:");
    (cur->type==ID)?show_int(cur->id):show_char("OP");

    switch (cur->parent->type){
        case OP_AND:
            if(cur->parent->value ^
               (cur->parent->left->value & cur->parent->right->value))
                return flip(cur->parent);
            break;
        case OP_OR:
            if(cur->parent->value ^
               (cur->parent->left->value | cur->parent->right->value))
                return flip(cur->parent);
            break;
    }

}

int main(){
    (FILE_MODE)?freopen("input.txt","r",stdin):1;
    int T,N,M;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d\n",&N,&M);
        Node* root = NULL;
        Node_list = (Node**)malloc((N+1)*sizeof(Node*));
        show_int(N);show_int(M);
        construct_tree(&root);
        LOGGING("Built tree\n\n\n\n");
        for(int i=0;i<M;i++){
            int target;
            scanf("%d",&target);
            show_int(target);
            flip(Node_list[target]);
            printf("%d\n",root->value);
        }

        free(Node_list);
        free_tree(root);
    }
    return 0;
}
