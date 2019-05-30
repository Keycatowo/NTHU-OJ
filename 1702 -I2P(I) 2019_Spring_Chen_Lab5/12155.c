#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define MAX 1005


int n,r,one=0,black=0;
int x[MAX],y[MAX];
bool adj[MAX][MAX];
bool visited[MAX];

bool DFS(int i){
    bool is_leaf = true;
    for (int j=0;j<n;j++)
        if(adj[i][j] && !visited[j])
        {
            visited[j] = true;
            is_leaf = false;
            DFS(j);
        }
    return is_leaf;
}

void traversal(){
    memset(visited,false,n);
    for(int i=0;i<n;i++)
    if(!visited[i]){
        if(DFS(i))
            one++;
        else
            black++;
    }
}


int main()
{
    scanf("%d %d",&n,&r);
    for(int i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if( (x[i]-x[j])*(x[i]-x[j])
               +(y[i]-y[j])*(y[i]-y[j])
               <= r*r)
               adj[i][j]=adj[j][i] = true;
    traversal();
    printf("%d %d\n",one,black);
    return 0;
}
