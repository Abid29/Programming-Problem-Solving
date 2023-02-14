#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;while(t--){
        int x,y;
        cin>>x>>y;
        cout<<2*(x-y)<<endl;
        if(y==x-1){
            cout<<x-1<<' '<<x<<endl; continue;
        }
        cout<<x-1<<' '<<x<<' '<<x-1;
        for(int i=x-2;i>=y;i--) cout<<' '<<i;
        for(int i=y+1;i<x-1;i++) cout<<' '<<i;
        cout<<endl;
    }
}