#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define MAX 1005

int n,r,sum=0,one=0;
int x[MAX],y[MAX];
bool adj[MAX][MAX];
bool visited[MAX];
int group[MAX];


bool DFS(int i){
    bool is_leaf = true;
    for(int j=0;j<n;j++)
        if(adj[i][j] && !visited[j])
        {
            visited[j] = true;
            is_leaf = false;
            DFS(j);
        }
<<<<<<< HEAD
=======
//    if(is_leaf)
//        sum++;
>>>>>>> 9123e8856f74381415da6001be1e8416ec056bcf
    return is_leaf;
}

void traversal(){
    ///reset
    memset(visited,false,n);
    memset(group,MAX,n);
    for(int i=0;i<n;i++)
        if(!visited[i])
        {
            visited[i] = true;
            if(DFS(i))
                one++;
            else
                sum++;
        }
}

void input(){
    scanf("%d %d",&n,&r);
    for(int i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if( (x[i]-x[j])*(x[i]-x[j])
               +(y[i]-y[j])*(y[i]-y[j])
               <= r*r )
                adj[i][j]=adj[j][i]=true;
        }
    }
<<<<<<< HEAD
}

=======
//
//    for(int i=0;i<n;i++)
//    {
//        bool nothing = true;
//        for(int j=0;j<n;j++)
//            if(adj[i][j])
//                nothing = false;
//        if(nothing) one++;
//    }
}


>>>>>>> 9123e8856f74381415da6001be1e8416ec056bcf
int main(){
    freopen("sample.txt","r",stdin);
    input();
    traversal();
    printf("%d %d\n",one,sum);
    return 0;
}
