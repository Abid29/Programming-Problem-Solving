#include <bits/stdc++.h>
using namespace std;
vector<int>album[200010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,i;
        cin>>n;
        for(i=1;i<=n;i++) album[i].clear();
        vector<pair<int,int>>vp;
        for(i=1;i<=n;i++){
            int k,x,j=1;
            cin>>k>>x;
            album[i].push_back(x);
            while(k-->1){
                cin>>x;
                if(x>album[i].back()) album[i].push_back(x);
            }
            vp.push_back({album[i].back(),i});
        }
        sort(vp.begin(),vp.end());

        set<int>coolness;
        map<int,int>dp;
        coolness.insert(0);
        int mx = 0;
        for(pair<int,int>p : vp){
            //cout<<p.first<<endl;
            int idx = p.second , sz = (int)album[idx].size();
            for(int val : album[idx]){
                auto it = coolness.lower_bound(val); --it;
                dp[p.first] = max(dp[p.first],mx);
                dp[p.first] = max(dp[p.first],dp[*it]+sz);
                //cout<<p.first<<' '<<sz<<' '<<dp[p.first]<<endl;
                mx = max(mx,dp[p.first]) , sz--;
                
            }
            coolness.insert(album[idx].back());
        }
        cout<<mx<<endl;

    }
}