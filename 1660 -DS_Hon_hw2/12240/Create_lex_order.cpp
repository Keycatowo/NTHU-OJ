#include<iostream>
using namespace std;

int main(){
    int S[1000];
    for (int i=0; i<1000;i++){
        cin>>S[i];
    }
    cout<<'[';
    for (int i=0; i<1000;i++){
        cout<<S[i]<<", ";
    }
    cout<<']';
    return 0;
}
