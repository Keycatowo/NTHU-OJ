#include <stdio.h>
#define lli long long int

lli fast_mod(lli x,lli  y,lli  m)
{
    if(y==0) return 1%m;
    if(y==1) return x%m;
    lli s = fast_mod(x,y/2,m);
    if(y%2)     // y is odd
    {
        return ( (( (s%m)*(s%m) )%m *x)%m );
    }
    else        // y is even
    {
        return  (((s%m)*(s%m) )%m);
    }
}

int main(){
    lli x,y,m;
    scanf("%lld %lld %lld",&x,&y,&m);
    printf("%lld\n",fast_mod(x%m,y,m));
    return 0;
}
