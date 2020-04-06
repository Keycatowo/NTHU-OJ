#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define ffor(k) for(int i=0;i<k;i++)


void rotateList(Node** root,int place){
    Node* origin_head = (*root);
    Node* cur=origin_head;

    for (int i=1;i<place;i++){
        cur = cur->next;
    }

    Node* new_head = cur->next;
    cur->next = NULL;

    for (cur = new_head; cur->next!=NULL; cur=cur->next){}

    cur->next = origin_head;

    (*root) = new_head;
}

