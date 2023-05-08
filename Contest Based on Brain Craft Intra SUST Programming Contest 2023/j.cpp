#include <bits/stdc++.h>
using namespace std;
long long n,m,k,i;
long long colcnt[100100],ans;
bool ind[100100];
vector<pair<long long,int>>pp;
vector<int>g[100100];

void dfs(int u,long long val){
    if(k==0) return;
    long long cnt = min(k,colcnt[u]);
    ans += cnt*val,k-=cnt,colcnt[u] = 0;
    if(k==0) return; 
    ind[u] = 1;
    for(int v : g[u]){
        if(ind[v]) continue;
        dfs(v,val);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--){
        cin>>n>>m>>k;
        for(i=1;i<=n;i++) colcnt[i]=0,ind[i]=0;
        for(i=0;i<n;i++){
            int x;
            cin>>x;
            colcnt[x]++;
            g[i+1].clear();
        }
        pp.clear();
        for(i=0;i<n;i++){
            long long val;
            cin>>val;
            pp.push_back({val,i+1});
        }
        sort(pp.begin(),pp.end());
        //reverse(pp.begin(),pp.end());

        while(m--){
            int x,y;
            cin>>x>>y;
            g[y].push_back(x);
        }
        ans = 0;
        for(pair<long long,int>pa : pp){
            long long val = pa.first;
            int colid = pa.second;

            dfs(colid,val);
            if(k==0) break;

        }
        cout<<ans<<'\n';
    
    }
}