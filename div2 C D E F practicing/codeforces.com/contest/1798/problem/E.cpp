#include <bits/stdc++.h>
using namespace std;
int a[300100],dp[300100],dp1[300100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,i; cin>>n;
        for(i=1;i<=n;i++){
            cin >> a[i];
        }

        map<int,int>mp;
        dp[n] = (a[n] == 0) ? 1:-1;

        for(i=n-1;i>0;i--){
            if(i+a[i]>n) dp[i] = -1;
            else if(i+a[i] == n) dp[i] = 1;
            else{
                if(dp[i+a[i]+1] == -1) dp[i] = -1;
                else                   dp[i] = dp[i+a[i]+1]+1;
            }
            if(dp[i]!=-1&&mp[dp[i]]==0) mp[dp[i]] = i;
        }
        mp[0] = n+1;

        dp1[n] = 1, dp[n+1] = 0,dp1[n+1] = 0;
        int mx = a[n]==0;

        for(i=n-1;i>0;i--){
            if(i+a[i]>n) dp1[i] = mx+1;
            else{
                dp1[i] = max(mx+1,1+dp1[i+a[i]+1]);
            }
            mx = max(mx,dp[i]);
            //cout<<i<<dp1[i]<<endl;
        }

        //cout<<dp1[2]<<endl;

        for(i=1;i<n;i++){
            if(a[i] == dp[i+1]) cout<<0<<' ';
            else{
                if((dp1[i+1]>=a[i] && a[i]!=0)||dp[i+1]!=-1){
                    //cout<<"1s"<<dp[i+1]<<' '<<dp1[i+1]<<' ';
                    cout<<1<<' ';
                }
                else              cout<<2<<' ';
            }
        }
        cout<<endl;
    }
}