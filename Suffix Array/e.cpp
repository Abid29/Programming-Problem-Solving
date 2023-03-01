#include <bits/stdc++.h>
using namespace std;

int n, l=20;
vector<int> adj[100010];
vector<pair<int,int>>one[100100];
vector<pair<int,int>>two[100100];
long long val1[100100],val2[100100];

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p;cin>>p;while(p--){
        cin>>n;
        int s,m,q;
        cin>>m>>s>>q;
        int x,y,t1,t2;
        map<pair<int,int>,int>m1;
        
        while(m--){
            cin>>x>>y>>t1>>t2;
            m1[{x,y}] = t1;
            m1[{y,x}] = t2;

        }
        int mn;cin>>mn;s--;
        while(s--){
            cin>>x; mn= min(x,mn);
        }
        while(q--){
            int a,b;
            int mmn = mn;
            cin>>a>>b;
            if(m1[{a,b}]!=0) mmn = min(mmn,m1[{a,b}]);
            cout<<mmn<<'\n';
        }

        
    }
    return 0;
}