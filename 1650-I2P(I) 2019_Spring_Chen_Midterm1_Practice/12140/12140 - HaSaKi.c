#include <stdio.h>
char S[1000];
char s[1000];


int getline(char*);
void show(char*,int);
int Find(int,int,int);



int main(){
    freopen("12140_sampleIn.txt","r",stdin);
    int N,n;
    N=getline(S);
    n=getline(s);
    int t,l,r;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d",&l,&r);
        printf("%d\n",Find(l-1,r-1,n));

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
        // count each all s
        if(check==length){
            sum++;
            check=0;
            j=0;
        }
    }
    //printf("%d\n",sum);
    return sum;
}
