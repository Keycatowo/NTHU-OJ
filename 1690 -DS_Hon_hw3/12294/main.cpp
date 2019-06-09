#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define Div 4294967296
#define n_max 131072
using namespace std;

int T,m,n;
//
//long long int mod(unsigned long long p,unsigned long long q)
//{
//    long long int k= p/q;
////    while(p>=q)
////        p-=q;
//    p -= k*q;
//    return p;
//}


unsigned long long H(unsigned long long m, unsigned long long n,unsigned long long x)
{
    return ((m*x)%Div)%n;
}


int main(){_

   // freopen("sample.txt","r",stdin);
    cin>>T;
    vector< vector <unsigned long long> > Q(n_max);
    unsigned long long k;
    while(T--)
    {
        cin>>m>>n;
        for(int i=0;i<n;i++)
        {
            cin>>k;
            Q[H(m,n,k)].push_back(k);
        }
        for(int i=0;i<n;i++)
        {
            if(Q[i].empty())
                cout<<"\n";
            else
            {
                cout<<Q[i][0];   // for head
                for(int j=1;j<Q[i].size();j++)
                {
                    cout<<" "<<Q[i][j];
                }
                cout<<"\n";         // for tail
                Q[i].clear();
            }
        }
    }
    return 0;

}


