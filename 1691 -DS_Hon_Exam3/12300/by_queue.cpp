#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int,vector<int>,greater<int> > pq;
int Count [26];


void input(){
    string S;
    cin>>S;
//    cout<<S.length()<<" :";
    while(!pq.empty())
        pq.pop();
    for(int i=0; i<26; i++)
        Count[i] = 0;
    for(int i=0;i<S.length();i++)
        Count[S[i]-'a'] ++;
	for(int i=0; i<26; i++)
        if(Count[i]!=0)
            pq.push(Count[i]);
}

void solve(){
	int ans=0;

	while (pq.size()>=2){
		int a=pq.top(); pq.pop();
		int b=pq.top(); pq.pop();

		pq.push(a+b);
		ans += a+b;
	}

	cout<<ans<<"\n";
}

int main(){
    freopen("sample.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        input();
        solve();
    }
	return 0;
}
