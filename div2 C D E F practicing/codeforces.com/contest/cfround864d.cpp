#include <bits/stdc++.h>
using namespace std;
long long im[100100],sz[100100],totim[100100],par[100100];
set<pair<long long,int>>st[100100];
vector<int>g[100100];

void dfs(int u,int p){
    sz[u] = 1, par[u] = p;
    totim[u] = im[u];
    long long val = 0;
    for(int v : g[u]){
        if(v == p) continue;
        dfs(v,u);
        sz[u] += sz[v];
        totim[u] += totim[v];
        st[u].insert({-sz[v],v});
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,u,v;
    cin>> n>> m;
    for(i=1;i<=n;i++) cin>>im[i];

    for(i=1;i<n;i++){
        cin >> u >>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);

    while(m--){
        cin >> u >> v;
        if(u == 1){
            cout<<totim[v]<<'\n';
        }
        else{
            long long szz = sz[v];
            long long imm = totim[v];
            if(st[v].empty()) continue;
            int hson = (*st[v].begin()).second;
            st[v].erase(st[v].begin());
            sz[v] -= sz[hson];
            totim[v] -= totim[hson];
            st[hson].insert({-sz[v],v});
            sz[hson] += sz[v];
            totim[hson] += totim[v];
            st[par[v]].insert({-sz[hson],hson});
            st[par[v]].erase(st[par[v]].find({-sz[hson],v}));
            par[hson] = par[v],par[v] = hson;
            
        }
    }
}