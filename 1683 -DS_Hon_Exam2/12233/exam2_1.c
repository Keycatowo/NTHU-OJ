#include<stdio.h>
#include<stdlib.h>

int T,V,E;
int pre[1000]={0};
int pool[1000]={0};
int isup[1000]={0};
int dia[1000]={0};

struct node{
    int key;
    struct node *next;
};

typedef struct node Node;
Node *list[1000];

Node* new_node(int k){
    Node *x = (Node*)malloc(sizeof(Node));
    x->key = k;
    x->next = NULL;
    return x;
}

void adj(int u,int v){

    Node *entry = new_node(v);
    entry->next = list[u];
    list[u] = entry;
    //printf("list_%d:%d\n",u,list[u]->key);

}

int head=0, tail=-1, num_ini=0;
void topo(){

    int i;
    for(i=0; i<V; i++){
        if(pre[i] == 0){
            tail++;
            pool[tail] = i;
            dia[i] = 1;
            num_ini++;
        }
    }

    while(head < V){

        Node *cur = list[pool[head]];

        while(cur != NULL){
            dia[cur->key] = dia[cur->key] + dia[pool[head]];
            if(dia[cur->key] > 1000000)
                dia[cur->key] = 1000000;
            pre[cur->key]--;
            //printf("curkey:%d\n", cur->key);
            if(pre[cur->key] == 0){

                tail++;
                pool[tail] = cur->key;
            }

            //for(int j=0; j<=tail; j++)
                //printf("%d ",pool[j]);
            //printf("\n");

            cur = cur->next;
        }

        head++;
    }
}

void clear(Node *root){

    if(root->next != NULL)
        clear(root->next);
    free(root);
}

int main(void){

    //freopen("test.txt", "r", stdin);

    scanf("%d",&T);
    int k;
    for(k=0; k<T; k++){

        scanf("%d",&V);
        scanf("%d",&E);

        int i;
        for(i=0; i<V; i++){
            pre[i] = 0;
            pool[i] = 0;
            list[i] = NULL;
            isup[i] = 0;
            dia[i] = 0;
            num_ini = 0;
        }

        head=0, tail=-1;

        int u,v;
        for(i=0; i<E; i++){
            scanf("%d",&u);
            scanf("%d",&v);
            adj(u,v);
            pre[v]++;
            isup[u]++;
        }

        //Node *temp = list[2];
        //while(temp != NULL){
            //printf("list2_%d ",temp->key);
            //temp = temp->next;
        //}

        topo();

        int sum=0;
        for(i=0; i<V; i++)
            sum = sum + dia[i];

        //for(i=0; i<V; i++)
            //printf("%d ",dia[i]);

        sum = sum - num_ini;
        printf("%d\n",sum);

        for(i=0; i<V; i++){
            if(list[i] != NULL && list[i]->next != NULL)
                clear(list[i]->next);
        }

    }

    return 0;
}

