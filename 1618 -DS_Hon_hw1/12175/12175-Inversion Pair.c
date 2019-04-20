#include <stdio.h>
int SUM=0;

void MergeSort(int* A,int x, int y, int* T){
    //int sum=0;
    if(y-x>1){//if length bigger than 1
        int m=(x+y)/2; //first divide
        int p=x, q=m, i=x;/// p/q is the head of left/right,i is where we at
        MergeSort(A,x,m,T);///recursive the left side
        MergeSort(A,m,y,T);///recursive the right side
        while(p<m||q<y){//while the left and right not go the end
            if(q>=y||(p<m&&A[p]<=A[q]))///when right at end  /or/ left not end ,also left is smaller than right
                T[i++]=A[p++];//take left to temp, go next
            else{
                T[i++]=A[q++];//take right to temp, go next
                SUM+=m-p;
            }
        }
        for (i=x;i<y;i++) A[i]=T[i];//move all data from T back to A
    }
    //return sum;
}


int main(){
    int N;
    scanf("%d",&N);
    int A[N],B[N];
    for (int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    MergeSort(A,0,N,B);
    printf("%d\n",SUM);

    return 0;
}
