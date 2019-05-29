#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define MAX 1000

char strs[SIZE][MAX];
char *ptrs[SIZE];

int compare_str_ptr(const void *a, const void *b)
{
    char **pa;
    char **pb;
    pa = (char **) a;
    pb = (char **) b;
    return -strcmp(*pa, *pb);
}


int main(void)
{
    int i;
    int n;
    freopen("sample.txt","r",stdin);
    ///input
    scanf("%d",&n);
    gets(strs[0]);
    for (i=0; i<n; i++){
        gets(strs[i]);
        ptrs[i] = strs[i];
    }


    qsort(ptrs, n, sizeof(char*), compare_str_ptr);
    for(i=0;i<n;i++)
        printf("%s",ptrs[i]);

/*
    printf("strs: ");
    for (i=0; i<=n; i++) {
        printf("%s ", strs[i]);
    }
    printf("\n");

    for (i=0; i<SIZE; i++) {
        ptrs[i] = strs[i];
    }

    printf("ptrs: ");
    for (i=0; i<n; i++) {
        printf("%p ", ptrs[i]);
    }
    printf("\nafter sorting\n");

    qsort(ptrs, n, sizeof(char*), compare_str_ptr);

    printf("ptrs: ");
    for (i=0; i<n; i++) {
        printf("%p ", ptrs[i]);
    }
    printf("\n");

    printf("ptrs: ");
    for (i=0; i<n; i++) {
        printf("%s ", ptrs[i]);
    }
    printf("\n");

    printf("strs: ");
    for (i=0; i<n; i++) {
        printf("%s ", strs[i]);
    }
*/


    return 0;
}
