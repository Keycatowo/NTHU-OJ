#include <stdio.h>
char S[1000];//hasahasasaki
char s[1000];//sa
int times[1001];//to store how many times s in S 1~1000

int getline(char* Seq);
void show(char* Seq,int length);
int Find(int start,int end,int length);
void build(int N,int n);
int count_times(int l,int r,int n);



int main(){
    /// input S s
    freopen("12140_sampleIn.txt","r",stdin);
    int N,n;
    N=getline(S);
    n=getline(s);

    /// Build times array
    build(N,n);

    /// t queries
    int t,l,r;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d",&l,&r);
        //printf("%d\n",Find(l-1,r-1,n));
        printf("%d\n",count_times(l,r,n));
    }
    return 0;
}


int getline(char* Seq){
    char tmp;
    int i=0;
    while( (tmp=getchar())!='\n' ){
        Seq[i]=tmp;
        i++;
    }
    return i;
}

void show(char* Seq,int length){
    for(int i=0;i<length;i++){
        printf("%c",Seq[i]);
    }
}

int Find(int start,int end,int length){
    int sum=0;
    int check=0,j=0;
    // lengthg(s)=1
    if(length==1)
    {
        for(int i=start;i<=end;i++){
            if(S[i]==s[0]) sum++;
        }
        return sum;
    }

    for(int i=start;i<=end;i++){
        // judge each equal
        if(S[i]==s[j])
        {
            check++;
            j++;
        }
        else
        {
            check=0;
            j=0;
        }
        // count each all substring(s) in sting(S)
        if(check==length){
            sum++;
            check=0;
            j=0;
        }
    }
    //printf("%d\n",sum);
    return sum;
}
void build(int N,int n){
    for(int i=1;i<=N;i++){
        times[i]=Find(0,i-1,n);
    }
}
int count_times(int l,int r,int n){
    if(n>1)
    {
        return (times[r]-times[l]);
    }
    else
    {
        //if (l==r) return (times[l]-times[l-1]);
        return (times[r]-times[l-1]);
    }

}
