#include<bits/stdc++.h>
using namespace std;
long long md = 998244353;
int a[200100];

long long pw(long long a,long long b){
    long long ret = 1;
    while(b){
        if(b&1) ret = (ret * a)%md;
        a = (a*a)%md , b/=2;
    }
    return ret;
}

int main(){
    int t;cin>>t;while(t--){
        long long int n,i;
        cin>>n;
        long long zero = 0,ini=0;
        for(i=0;i<n;i++){
            cin >> a[i];
            zero += a[i] == 0;
        }
        for(i=0;i<zero;i++) ini += a[i]==0;
        vector<int>dp(zero+1,0);
        for(i=zero-1;i>=ini;i--){
            long long p = ((zero-i) * (zero-i)) % md; p = (p+p)%md;
            p = pw(p,md-2);
            p = (p*n)%md; p = (p*(n-1))%md;
            dp[i] = (dp[i+1] + p)%md;
        }
        cout<<dp[ini]<<endl;
    }
}