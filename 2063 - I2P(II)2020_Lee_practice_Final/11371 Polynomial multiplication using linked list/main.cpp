#include "function.h"
#include <bits/stdc++.h>
#define DEBUG

int main(void){
  freopen("11371.txt","r",stdin);
	Node *p1=create(); //polynomial linked list1
	Node *p2=create(); //polynomial linked list2
//	printNode(p2);
	Node *mul=multiple(p1,p2);
	printNode(mul);
	destroy(mul);
	destroy(p2);
	destroy(p1);
	return 0;
}
