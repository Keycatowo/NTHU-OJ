#include "function.h"

Node* createList(int *a, int size){
    Node* head = (Node*)malloc(sizeof(Node));
    Node* cur  = head;
    for(int i=0;i<size;i++){
        cur->data = a[i];
        if((i+1)<size){
            cur->next = (Node*)malloc(sizeof(Node));
            cur = cur->next;
        }
        else
            cur->next = NULL;
    }
    return head;

}


void deleteElementByIdx(Node** head, int idx){
    Node* cur = (*head);

    if(idx==0){
        Node* tmp = (*head);
        (*head)=tmp->next;
        free(tmp);
        return;
    }


    while(cur!=NULL){
        if(idx==1){
            Node* tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
            return;
        }
        cur=cur->next;
        idx--;
    }


    return ;
}
