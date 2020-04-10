#include <stdio.h>
#include <stdbool.h>
#define FILE_MODE 0
#define DEBUG_MODE 0
#define MAX_N 1005
#define MAX_RANGE 65536
#define New0(node) (node*)calloc(1,sizeof(node))
#define New(node) (node*)malloc(sizeof(node))
#define LOGGING(s) (DEBUG_MODE)?printf("%s",s):1
#define show_int(a) (DEBUG_MODE)?printf("%s:%d\n",#a,a):1
#define show_char(a) (DEBUG_MODE)?printf("%s:%c\n",#a,a):1


int row,col;
int matrix[MAX_N][MAX_N];
bool finished[MAX_RANGE];
bool result[MAX_RANGE];
bool marked[MAX_N][MAX_N];

void input();

void find_mark(int x,int y,int value){
    if(marked[x][y] || x<1 || y<1 || x>row || y>col)
        return;

    if(matrix[x][y]==value)
        marked[x][y] = true;
    else
        return;

    find_mark(x-1,y,value);
    find_mark(x+1,y,value);
    find_mark(x,y-1,value);
    find_mark(x,y+1,value);
}



int main(){
    (FILE_MODE)?freopen("input.txt","r",stdin):1;

    input();
    int target;
    for(int i=1;i<=row;i++)
        for (int j=1;j<=col;j++)
        {
            if(marked[i][j]==false){
                target = matrix[i][j];
                find_mark(i,j,target);
                if(finished[target])
                    result[target] = true;
                finished[target] = true;
            }
        }

    (DEBUG_MODE)?show_matrix():0;
    bool check = true;
    for(int i=0;i<MAX_RANGE;i++){
        if(result[i]){
            printf("%d\n",i);
            check = false;
        }
    }
    if(check)
        printf("ABSTRACT\n");

    return 0;
}


void input(){
    scanf("%d %d\n",&row,&col);
    for(int i=1;i<=row;i++)
        for (int j=1;j<=col;j++)
            scanf("%d",&matrix[i][j]);
}

void show_matrix(){
    for(int i=1;i<=row;i++){
        for (int j=1;j<=col;j++)
            printf("%d",matrix[i][j]);
        printf("\n");
    }
}
