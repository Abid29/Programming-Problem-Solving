#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,x,p;
        cin>>n>>x>>p;
        p=min(p,2*n);
        int lagbe = (n-x)%n,tot=0,i;
        for(i=1;i<=p;i++){
            tot=(tot+i)%n;
            if(tot==lagbe) break;
        }
        if(i==p+1) cout<<"No\n";
        else       cout<<"Yes\n";
    }
}