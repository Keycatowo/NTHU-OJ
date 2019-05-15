#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 15


int Q[MAX_N],C[MAX_N];// 皇后Q亦儲存於城堡C內
int sum=0;
int E=0;              // 邊界
int N,M;

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
        if(C[i] == pos) return false;
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
        if( diff(i,checks) == diff(C[i],pos)) return false;
    }
    return true;

}

void solve(int Qs,int Cs,int now_col){
    if(Qs==0 && Cs==0) sum++;   //當沒有要放的時候，表示完成一種棋面
    else
    {
        for(int i=0; i<E; i++)
        {
            if(valid_C(i,now_col))   // 先檢查是否可以放城堡
            {
                /// C
                if(Cs>0)
                {
                   C[now_col] = i;              // 放城堡
                   solve(Qs,Cs-1,now_col+1);    // 放完往下走
                   C[now_col] = 0;              // 走完記得拿掉
                }

                /// Q
                if(valid_Q(i,now_col) && Qs>0)  //再檢查是否可以放皇后
                {
                    C[now_col] = i;
                    Q[now_col] = i;
                    solve(Qs-1,Cs,now_col+1);
                    C[now_col] = 0;
                    Q[now_col] = 0;
                }
            }
        }
    }
}


int main()
{
    scanf("%d %d",&N,&M);
    E= N+M;
    solve(N,M,0);
    printf("%d\n",sum);
    return 0;
}
