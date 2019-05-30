#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define MAX 1005

int n;
char *ptr[MAX];
char str[MAX][MAX];
bool check=true;



int cmp(const void *a,const void *b){
    char **pa =(char**) a;
    char **pb =(char**) b;
    bool is_subset = false;
    int len_a=strlen(*pa),len_b=strlen(*pb);
    int m=abs(len_a-len_b);
    int k=min(len_a,len_b);
    if(len_a == len_b)
    {
        if(strcmp(*pa,*pb)==0)
            is_subset = true;
        else
            return len_a-len_b;
    }
    else if(len_a > len_b)
    {
        for(int i=0;i<m;i++)
            if(strncmp(*pa+i,*pb,k)==0)
                is_subset = true;
    }
    else
    {
        for(int i=0;i<=m;i++)
            if(strncmp(*pa,*pb+i,k)==0)
                is_subset = true;
    }
    if(!is_subset) check =false;
    return len_a-len_b;
}

int main()
{
    scanf("%d",&n);
    gets(str[0]);
    for(int i=0;i<n;i++)
    {
        gets(&str[i]);
        ptr[i]= str[i];
    }
    qsort(ptr,n,sizeof(char*),cmp);
    if(check)
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
            puts(ptr[i]);
    }
    else
        printf("NO\n");


    return 0;
}
