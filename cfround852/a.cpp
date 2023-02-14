#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;while(t--){
        long long a,b,n,m;
        cin>>a>>b>>n>>m;
        if((m+1)*b<m*a){
            long long ans = n*b;
            cout<<ans<<endl;
        }
        else{
            long long k = n/(m+1);
            long long ans = k*m*a;
            ans += (n%(m+1)) * min(a,b);
            cout<<ans<<endl;
            continue;
        }
    }
}