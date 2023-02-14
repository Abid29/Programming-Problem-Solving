#include<bits/stdc++.h>
using namespace std;
long long a[100005],dp[10005];
int main(){
    int i,n,s;
    cin>>n>>s;
    for(i=1;i<=n;i++) cin>>a[i];
    dp[0] = 1;
    int l=1,r=2,ans=1e6;
    dp[a[l]] = 1;

    if(dp[s] == 1){
        cout<<1;return 0;
    }


    while(r<=n){
        for(i=s;i>=a[r];i--){
            dp[i] += (dp[i-a[r]]);
        }
        r++;
        while(dp[s]>0){
            //cout<<r<<" "<<l<<" "<<dp[s]<<endl;
            ans = min(ans,r-l);
            for(i=0;i<s;i++){
                if(dp[i]) dp[i+a[l]] -= dp[i];
            }
            l++;
        }

    }
    if(ans==1e6) ans = -1;
    cout<<ans;
}