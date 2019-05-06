#include <bits/stdc++.h>
#include <cstdbool>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int pre[65536],in[65536],post[65536],out[65536];
int pos,pos2;

int Findin(int what)
{
    for(int i=0;i<65536;i++)
        if(in[i]==what) return i;
}
void postorder(int in_start,int in_end)
{
    if(in_start> in_end) return;

    int m=Findin(pre[pos]);
    int show=pre[pos];
    pos++;

    postorder(in_start,m-1);    //L
    postorder(m+1,in_end);      //R
//    cout<<show<<" ";            //D
    out[pos2]=show;
    pos2++;
}
void preorder(int in_start,int in_end,int post_start,int post_end)
{
    if(in_start> in_end||post_start>post_end) return;
//    int m=Findin(post[post_end])-in_start;
    int m;
    for(int i=in_start;i<=in_end;i++){
        if(in[i]==post[post_end])
            m=i-in_start;
    }
    int show=post[post_end];

//    cout<<show<<" ";                                                    //D
    out[pos]=show;
    pos++;
    preorder(in_start,in_start+m-1,post_start,post_start+m-1);          //L
    preorder(in_start+m+1,in_end,post_start+m,post_end-1);              //R


}

int main(){_
    /// input
    freopen("sample input.txt","r",stdin);
    int N1,N2;
    /// N1
    cin>>N1;
    for(int i=0;i<N1;i++)
        cin>>pre[i];
    for(int i=0;i<N1;i++)
        cin>>in[i];
    pos=0;
    postorder(0,N1-1);
    for(int i=0;i<N1;i++)
        cout<<out[i]<<" ";
    cout<<"\n";
    /// N2
    cin>>N2;
    for(int i=0;i<N2;i++)
        cin>>post[i];
    for(int i=0;i<N2;i++)
        cin>>in[i];
//    for(int i=0;i<N2;i++)
//        cout<<post[i];
//    cout<<"\n";
//    for(int i=0;i<N2;i++)
//        cout<<in[i];
//    cout<<"\n";
    pos=0;
    preorder(0,N2-1,0,N2-1);
    for(int i=0;i<N2;i++)
        cout<<out[i]<<" ";
    cout<<"\n";
    return 0;
}
