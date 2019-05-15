#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#define MAX_N 13

//bool I[MAX_N],J[2*MAX_N-1],L[2*MAX_N-1];   //
//int N;
//int sum=0;
//
//void solve(int row){
//    for(int col=0; col<N; col++){
//        int j = row + col;
//        int l = N-1-row+col;
//        if(I[col] || J[j] || L[l]){}
//        else if(row == N-1)
//            sum++;
//        else
//        {
//            I[col]=J[j]=L[l] =true;
//            solve(row + 1);
//            I[col]=J[j]=L[l] =false;
//        }
//    }
//
//}

int N;
int sum=0;
void solve2(int row, int col, int J, int L){
    int able = ((1<<N)-1) & ~(col|J|L);
    /*
        (1<<N)-1    ����
        &           �h��
        ~col|J|L    ����񪺬ۤ�->�i�H��

    */
    while(able){        // �u�n�٦��i�H��
        int pos = able & -able;
        /// lowbit �ާ@ ���X�̥k��1
        /* example
                     a = 00110100
                    ~a = 11001011
                    -a = 11001100
                a & -a = 00000100
        */
        able ^= pos;    // ���X����able������
        if(row == N-1)  //��̫�@��F
            sum++;
        else
            solve2(row+1,col|pos,(J|pos)>>1,(L|pos)<<1);

    /*
        row+1       �U�@��
        col|pos     ��C�ۦP����
        (J|pos)>>1  �J����Ѷǻ�
        (L|pos)<<1  �Χ����@�۲�
    */
    }
}

int main()
{
    scanf("%d",&N);
//    solve(0);
    solve2(0,0,0,0);
    printf("%d\n",sum);
    return 0;
}
