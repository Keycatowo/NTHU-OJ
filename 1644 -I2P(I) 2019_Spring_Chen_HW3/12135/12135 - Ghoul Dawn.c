#include <stdio.h>
#include <limits.h>
#include <math.h>

void tm(char C,int i){
    printf("[%c]=%d\n",C,i);
}


long long int max_average(long long int* S,int least,int length){
    long long int MAX_AVERAGE=0,m=0;
    long long int sum=0,tmp=0;
    for(int i=least;i<=length;i++){
        //從最小區間上界開始
        ///tm('i',i);
        //從上界往回走，抓到最大為止
        for(int j=i-least;j>=0;j--){
            sum=S[i]-S[j];//從 j+1 j+2 ... i 為止(i-j)個數的和
            tmp=sum*10000/(i-j);// 此i-j之平均 因取3位故*1000
            ///printf("\tj=%d sum=%lld tmp=%lld \n",j,sum,tmp);
            //if(tmp<m) break;// 如果變小了，那就不要再走下去了
            if(tmp>m) m=tmp;
            ///printf("\t\tm=%lld\n",m);
        }
        ///printf("%lld?%lld %d\n",m,MAX_AVERAGE,(m-MAX_AVERAGE)>0);
        if((m-MAX_AVERAGE)>0){
            //如果找到一個比較大的，替換掉
            ///printf("MAX=%lld->%lld\n",MAX_AVERAGE,m);
            MAX_AVERAGE=m;
            m=0;
        }
        else{
            //否則清零就好
            ///printf("MAX=%lld\n",MAX_AVERAGE);
            m=0;
        }
    }
    return MAX_AVERAGE;
}

int main(){
    freopen("12135_sampleIn.txt","r",stdin);
    int n,k;
    scanf("%d %d",&n,&k);
    long long int S[n+1];
    S[0]=0LL;
    int scan;
    for (int i=0;i<n;i++){
        scanf("%d",&scan);
        //printf("%d\n",scan);
        S[i+1]=S[i]+scan;
        //printf("% lld\n",S[i+1]);
    }
//    for (int i=0;i<=n;i++){
//        printf("%lld\n",S[i]);
//    }
    long long int result=max_average(S,k,n);
    printf("%lld.%03lld\n",result/10000,((result%10000)+5)/10);
///測資1~5直接舍去無差，但測資6需四捨五入進位（SID1884721 1884727）
    return 0;
}
