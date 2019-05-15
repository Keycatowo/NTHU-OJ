#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 15


int Q[MAX_N],C[MAX_N];// �ӦZQ���x�s�󫰳�C��
int sum=0;
int E=0;              // ���
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
        �U�@�B������bpos��m(0~N-1)
        �e����checks��A�ҥH�n�ˬd����h��
        �u�n�ˬd�O�_���b�P�@��C�Y�i
    */
    for(int i=0;i<checks;i++){
        if(C[i] == pos) return false;                           // �ˬd�O�_�|�Q��u����
        if( diff(i,checks) == diff(Q[i],pos)) return false;     // �ˬd�O�_�|�Q�׽u�����]�u�Ҽ{Q�^
    }
    return true;
}

bool valid_Q(int pos,int checks){
    /*
        �U�@�B�ӦZ��bpos��m(0~N-1)
        �e����checks��A�ҥH�n�ˬd����h��
        �ˬd�O�_�b�P�@��C�浹������
        �u�ˬd�O�_�b�P�@�׽u
            �{�b�n�񪺬Ochecks��pos�C
            �ˬd���Oi�q0��checks-1�檺Q[i]�C
            ��t=�C�t �Y�b�P�@�׽u
    */
    for(int i=0;i<checks;i++){
        if(C[i] == pos) return false;                           // �ˬd�O�_�|�Q��u����
        if( diff(i,checks) == diff(C[i],pos)) return false;     // �ˬd�O�_�|�Q�׽u�����]�Ҽ{C�^
    }
    return true;

}

void solve(int Qs,int Cs,int now_col){
    if(Qs==0 && Cs==0)
    {
//        show();
        sum++;   //��S���n�񪺮ɭԡA��ܧ����@�شѭ�
    }
    else
    {
        for(int i=0; i<E; i++)
        {
            /// C
            if(valid_C(i,now_col) && Cs>0)   // ���ˬd�O�_�i�H�񫰳�
            {
                C[now_col] = i;              // �񫰳�
                solve(Qs,Cs-1,now_col+1);    // �񧹩��U��
                C[now_col] = -100;              // �����O�o����
            }

            /// Q
            if(valid_Q(i,now_col) && Qs>0)  //�A�ˬd�O�_�i�H��ӦZ
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


int main()
{
    scanf("%d %d",&N,&M);
    E= N+M;
    init();
    solve(N,M,0);
    printf("%d\n",sum);
    return 0;
}
