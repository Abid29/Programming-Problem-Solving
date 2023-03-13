#include <bits/stdc++.h>
using namespace std;
long long md = 998244353;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        long long l,r;
        cin>>l>>r;
        if(r==l){
            cout<<"1 1\n";continue;
        }
        long long re = r/l,i;
        for(i =0;i<33;i++) if((1<<i)>re) break;
        long long mx=i;
        if(mx == 1){
            cout<<1<<' '<<r-l+1<<'\n';continue;
        }
        long long mul = 1<<(mx-1);
        long long last = mul * l;
        //cout<<r<<' '<<last<<endl;
        long long ans = 1+(r-last)/mul;
        mul/=2,mul*=3;
        last = mul*l;
        if(last<=r){
            ans=(ans+(1+((r-last)/mul))*(mx-1))%md;
        }
        cout<<mx<<' '<<ans<<'\n';
    }
}