#include <stdio.h>
#include <stdlib.h>
#include "function.h"


Node* createList(){
    // create a new head
    Node* head = (Node*)malloc(sizeof(Node));
    Node* cur = head;
    // input data
    int n;
    /* for head node*/
    scanf("%d",&n);
    head->data = n;

    while(1){
        scanf("%d",&n);

        if(n!=-1){
            /* push new node in tail*/
            cur->next = (Node*)malloc((sizeof(Node)));
            cur->next->data = n;
            cur = cur->next;
        }
        else
        {
            cur->next = NULL;
            return head;
        }
    }




    return head;
}


Node* reverse(Node* head){
    Node* left = NULL;
    Node* cur = head;
    Node* right = head->next;

    while(1){

        // change point line
        cur->next = left;

        // move window
        left = cur;
        cur = right;
        right = right->next;

        // stop when
        if(right == NULL){
            cur->next = left;
            head = cur;
            return head;
        }
    }
}
