#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 15


int Q[MAX_N],C[MAX_N];// 皇后Q亦儲存於城堡C內
int sum=0;
int E=0;              // 邊界
int N,M;

void init(){
    for(int i=0;i<MAX_N;i++)
    {
        Q[i]=C[i]= -100;
    }
}
void show(){
    for(int i=0;i<E;i++)
        printf("%d ",C[i]);
    printf("\n");
    for(int i=0;i<E;i++)
        printf("%d ",Q[i]);
    printf("\n\n");
}
int diff(int a,int b){
    return (a>b?(a-b):(b-a));
}
bool valid_C(int pos,int checks){
    /*
        下一步城堡放在pos位置(0~N-1)
        前面有checks行，所以要檢查那麼多次
        只要檢查是否有在同一橫列即可
    */
    for(int i=0;i<checks;i++){
        if(C[i] == pos) return false;                           // 檢查是否會被橫線攻擊
        if( diff(i,checks) == diff(Q[i],pos)) return false;     // 檢查是否會被斜線攻擊（只考慮Q）
    }
    return true;
}

bool valid_Q(int pos,int checks){
    /*
        下一步皇后放在pos位置(0~N-1)
        前面有checks行，所以要檢查那麼多次
        檢查是否在同一橫列交給城堡做
        只檢查是否在同一斜線
            現在要放的是checks行pos列
            檢查的是i從0到checks-1行的Q[i]列
            行差=列差 即在同一斜線
    */
    for(int i=0;i<checks;i++){
        if(C[i] == pos) return false;                           // 檢查是否會被橫線攻擊
        if( diff(i,checks) == diff(C[i],pos)) return false;     // 檢查是否會被斜線攻擊（考慮C）
    }
    return true;

}

void solve(int Qs,int Cs,int now_col){
    if(Qs==0 && Cs==0)
    {
//        show();
        sum++;   //當沒有要放的時候，表示完成一種棋面
    }
    else
    {
        for(int i=0; i<E; i++)
        {
            /// C
            if(valid_C(i,now_col) && Cs>0)   // 先檢查是否可以放城堡
            {
                C[now_col] = i;              // 放城堡
                solve(Qs,Cs-1,now_col+1);    // 放完往下走
                C[now_col] = -100;              // 走完記得拿掉
            }

            /// Q
            if(valid_Q(i,now_col) && Qs>0)  //再檢查是否可以放皇后
            {
                C[now_col] = i;
                Q[now_col] = i;
                solve(Qs-1,Cs,now_col+1);
                C[now_col] = -100;
                Q[now_col] = -100;
            }


        }
    }
}



void solve2(int row,int col,int QJ,int QL,int CJ,int CL,int Qs,int Cs){
//    if(Qs==0 && Cs==0) sum++;
    if(Cs>=0){
        int able = ((1<<E)-1) & ~(col|QJ|QL);
        while(able){
            int pos = able & -able;
            able ^= pos;
            if(row == E-1) sum++;
            else
                solve2(row+1,col|pos,QJ>>1,QL<<1,(CJ|pos)>>1,(CL|pos)<<1,Qs,Cs-1);
        }
    }
    if(Qs>=0){
        int able = ((1<<E)-1) & ~(col|QJ|QL|CJ|CL);
        while(able){
            int pos = able & -able;
            able ^= pos;
            if(row == E-1) sum++;
            else
                solve2(row+1,col|pos,(QJ|pos)>>1,(QL|pos)<<1,CJ>>1,CL<<1,Qs,Cs-1);
        }
    }

//    int Cable = ((1<<E)-1) & ~(col|QJ|QL);
//    int Qable = ((1<<E)-1) & ~(col|QJ|QL|);
//




}


int main()
{
    scanf("%d %d",&N,&M);
    E= N+M;
    init();
    solve(N,M,0);
    printf("%d\n",sum);
    sum=0;
    solve2(0,0,0,0,0,0,N,M);
    printf("%d\n",sum);
    return 0;
}
