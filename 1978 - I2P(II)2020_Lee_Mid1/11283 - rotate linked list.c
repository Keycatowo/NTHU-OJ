#include "function.h"
#include <stdio.h>

void rotateList(Node** head,int N){
    Node* ori_head=(*head);
    Node* new_head=NULL;

    Node* cur=ori_head;

    for (int i=1;i<N;i++)
    {
        cur = cur->next;
    }
    new_head = cur->next;
    cur->next = NULL;

    for (cur = new_head; cur->next!= NULL; cur=cur->next){}
    cur->next = ori_head;

    (*head) = new_head;

}
