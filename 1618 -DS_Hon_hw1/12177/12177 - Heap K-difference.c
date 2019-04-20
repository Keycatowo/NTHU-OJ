#include<stdio.h>
#include<stdlib.h>
int diff_abs(int a,int b){
    if(a>b)return (a-b);
        else return (b-a);
}
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
/*
int compare(const void *arg1,const void *arg2){
    return(*(int *)arg1 -*(int *)arg2);
}*/
void MergeSort(int* A,int x, int y, int* T){
    if(y-x>1){//if length bigger than 1
        int m=(x+y)/2; //first divide
        int p=x, q=m, i=x;/// p/q is the head of left/right,i is where we at
        MergeSort(A,x,m,T);///recursive the left side
        MergeSort(A,m,y,T);///recursive the right side
        while(p<m||q<y){//while the left and right not go the end
            if(q>=y||(p<m&&A[p]<=A[q]))///when right at end  /or/ left not end ,also left is smaller than right
                T[i++]=A[p++];//take left to temp, go next
            else
                T[i++]=A[q++];//take right to temp, go next
        }
        for (i=x;i<y;i++) A[i]=T[i];//move all data from T back to A
    }
}
void Build(int n,int* A){
    if(rand()%2) qsort((void *)A,n,sizeof(int),compare);
        else {
            int B[n];
            MergeSort(A,0,n-1,B);
        }

}
void Update(int n,int* A){
    // i:father i*2+1:left (i+1)*2:right
    int i=0;
    while (i<n){
        //printf("i=%d\n",i);
        if((i*2+1)>=n) break;//no left child,also no right child
        //printf("have child\n",i);
        if((i+1)*2>=n){//only left child
            //printf("have left child\n");
            if(A[i]>A[i*2+1]){
                swap(&A[i],&A[i*2+1]);//father is bigger than child,swap them
                i=i*2+1;
                break;
            }
            else break;
        }
        //have both left and right child
        if((A[i]>A[i*2+1])||(A[i]>A[(i+1)*2])){//need to change
            //printf("Need change\n");
            if (A[i*2+1]<=A[(i+1)*2]){
                swap(&A[i],&A[i*2+1]);
                i=i*2+1;
            }

            else{
                 swap(&A[i],&A[(i+1)*2]);
                 i=(i+1)*2;
            }
        }else break;
    }
}
int pop_min(int n,int* A){
    int min=A[0];
    A[0]=A[n-1];
    Update(n-1,A);
    return min;
}
void insert_new(int n,int* A,int new_data){
    int i=n-1;//length of all
    A[i]=new_data;
    while(i>0){
        if(A[(i-1)/2]>A[i]){
            swap(&A[(i-1)/2],&A[i]);
            i=(i-1)/2;
        }else break;
    }
}
int main(){
    freopen("12177_sampleIn.txt", "r", stdin);
    //printf("%d\n",rand()%2);

    int N;//array length
    scanf("%d",&N);
    int Seq1[N],Seq2[N];
    for (int i=0;i<N;i++) scanf("%d",&Seq1[i]);
    for (int i=0;i<N;i++) scanf("%d",&Seq2[i]);
    Build(N,Seq1);
    Build(N,Seq2);
    int k,a,b;
    scanf("%d",&k);
    int diff,sum;
    int k_diff=0;
    for(int i=1;i<=k;i++){
        //printf("k=%d:",i);
        for(int j=1;j<=k;j++){
            a=Seq1[0];
            b=Seq2[0];
            //diff=abs(a-b);
            sum=a+b;
            Seq1[0]=sum;
            Seq2[0]=sum;
            //printf("%d %d %d %d \n",a,b,diff,sum);
            Update(N,Seq1);
            Update(N,Seq2);
            //insert_new(N,Seq1,sum);
            //insert_new(N,Seq2,sum);
        }
        k_diff+=diff_abs(a,b);
    }
    printf("%d\n",k_diff);

    return 0;
}
