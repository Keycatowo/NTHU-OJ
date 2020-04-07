#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define FILE_MODE 1
#define DEBUG_MODE 1
#define MAX_N 505
#define New(node) (node*)malloc(sizeof(node))
#define New0(node) (node*)calloc(1,sizeof(node))
#define ffor(k) for(int i=0;i<k;i++)
#define show(a) (DEBUG_MODE)?printf("%s:%d\n",#a,a):1
#define LOGGING(s) (DEBUG_MODE)?printf("logs:\t%s\n",s):1
#define min(a,b) ((a<b)?a:b)
#define diff(a,b) ((a>b)?(a-b):(b-a))

bool matrix[MAX_N][MAX_N];
bool is_A[MAX_N][MAX_N];
bool is_B[MAX_N][MAX_N];
bool row_A_with_data[MAX_N];
bool col_A_with_data[MAX_N];
bool row_B_with_data[MAX_N];
bool col_B_with_data[MAX_N];

int row,col;
int x1,y1,x2,y2;

void input();
void findA(int x1,int y1);
void findB(int x2,int y2);
void show_AB();


int main(){
    (FILE_MODE)?freopen("12657_input.txt","r",stdin):1;

    scanf("%d %d\n",&row,&col);
    scanf("%d %d\n",&x1,&y1);
    scanf("%d %d\n",&x2,&y2);
    input();
    LOGGING("finish input map");
    show(x1);show(y1);
    findA(x1,y1);
    findB(x2,y2);

    (DEBUG_MODE)?show_AB():1;
    int min_dis = MAX_N;


    // row search
    for(int i=1;i<=row;i++){
        if(row_A_with_data[i]&&row_B_with_data[i]){
            for(int p=1;p<=col;p++)
                for(int q=1;q<=col;q++){
                    if(is_A[i][p]&&is_B[i][q])
                        min_dis = min(min_dis,diff(p,q));
                }
        }
    }

    // col search
    for(int i=1;i<=col;i++){
        if(col_A_with_data[i]&&col_B_with_data[i]){
            for(int p=1;p<=row;p++)
                for(int q=1;q<=row;q++){
                    if(is_A[p][i]&&is_B[q][i])
                        min_dis = min(min_dis,diff(p,q));
                }
        }
    }



    if (is_A[x2][y2])
        printf("0\n");
    else if(min_dis==MAX_N)
        printf("-1\n");
    else
        printf("%d\n",min_dis-1);

    return 0;
}


void input(){
    char tmp;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            is_A[i][j] = false;
            is_B[i][j] = false;
            tmp = getchar();
            switch (tmp){
                case '1':
                    matrix[i][j] = true;
                    break;
                case '0':
                    matrix[i][j] = false;
                    break;
                default:
                    show("error");
            }
        }
        getchar();// for "\n"
    }

}

void findA(int x1,int y1){
    if(is_A[x1][y1]==true ||
       x1<1 || y1<1 || x1>row || y1>col)
        return;

    LOGGING("In findA");
    show(x1);show(y1);

    if(matrix[x1][y1]==true){
        is_A[x1][y1] = true;
        row_A_with_data[x1]=true;
        col_A_with_data[y1]=true;
    }

    else
        return;

    findA(x1+1, y1);
    findA(x1-1, y1);
    findA(x1,   y1+1);
    findA(x1,   y1-1);
}

void findB(int x2,int y2){
    if(is_B[x2][y2]==true ||
       x2<1 || y2<1 || x2>row || y2>col)
        return;

    LOGGING("In findB");
    show(x2);show(y2);

    if(matrix[x2][y2]==true){
        is_B[x2][y2] = true;
        row_B_with_data[x2]=true;
        col_B_with_data[y2]=true;
    }
    else
        return;

    findB(x2+1, y2);
    findB(x2-1, y2);
    findB(x2,   y2+1);
    findB(x2,   y2-1);
}


void show_AB(){
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            (is_B[i][j]||is_A[i][j])?printf("1"):printf("0");
        }
        printf("\n");
    }
}
