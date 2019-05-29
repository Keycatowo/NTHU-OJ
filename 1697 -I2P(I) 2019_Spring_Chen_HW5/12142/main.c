#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define MAX 1000
#define min(a,b) (a<b?a:b)


char strs[SIZE][MAX];
char *ptrs[SIZE];

int compare_str_ptr(const void *a, const void *b)
{
    /*
        a is something pointer
        let it be the pointer to pointer to char
        clam pa is a pointer to pointer to char
        *pa is the pointer to char,that means the head of string
    */
    char **pa = (char **) a;
    char **pb = (char **) b;
    int len_a=strlen(*pa),len_b=strlen(*pb);
    int m = min(len_a,len_b);//get the min length of two string
    int cmp = strncmp(*pa,*pb,m);
    int pre_a=0,pre_b=0;
    while(!cmp){
        // same length and same compare
        if( (len_a-pre_a) == (len_b-pre_b) )
            return 0;
        // not same length, keep Euclidean compare
        else if( (len_a-pre_a) >  (len_b-pre_b) )
            pre_a += m;
        else
            pre_b += m;
        m=min(len_a-pre_a,len_b-pre_b);
        cmp = strncmp(*pa + pre_a, *pb + pre_b,m);
    }
    // not same will direct return result
    return cmp;
}


int main(void)
{
    int i;
    int n;
    freopen("sample.txt","r",stdin);
    ///input
    while(scanf("%d",&n)!= EOF){
        gets(strs[0]);
        for (i=0; i<n; i++){
            gets(strs[i]);
            ptrs[i] = strs[i];
        }
        qsort(ptrs, n, sizeof(char*), compare_str_ptr);
        for(i=0;i<n;i++)
            printf("%s",ptrs[n-1-i]);
        printf("\n");
    }

    return 0;
}
