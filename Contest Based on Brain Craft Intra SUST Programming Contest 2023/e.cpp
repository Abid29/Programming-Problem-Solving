#include <bits/stdc++.h>
using namespace std;
long long md = 1000000007,fact[100100];

long long pw(long long a, long long b){
    long long ret = 1;
    while(b){
        if(b&1) ret = (ret * a)%md;
        b/=2, a = (a*a)%md;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for(long long i=1;i<=100000;i++){
        fact[i] = (fact[i-1]*i)%1000000006;
    }

    int t; cin >> t; while(t--){
        long long a,b,n;
        cin>> a >> b>> n;
        
        cout<<pw(n,fact[min(a,b)])<<'\n';
    }
}