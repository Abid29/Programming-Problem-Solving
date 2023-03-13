#include <bits/stdc++.h>
using namespace std;
vector<int>vv[400010];
bool ind[400010],cycle;

void dfs(int u,int par){
    ind[u] = 1;
    for(int v : vv[u]){
        if(v==par) continue;
        if(ind[v]) cycle = 1;
        else       dfs(v,u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i;
    cin>>n>>m;

    for(i=1;i<=n+n;i+=2){
        vv[i].push_back(i+1);
        vv[i+1].push_back(i);
    }

    while(m--){
        int u,v;
        char c,d;
        cin>>u>>c>>v>>d;
        u+=u,v+=v;
        u-=c=='R',v-=d=='R';
        vv[u].push_back(v);
        vv[v].push_back(u);

    }
    int x=0,y=0;
    for(i=1;i<=n+n;i++){
        cycle=0;
        if(ind[i]==0){
            dfs(i,0);
            if(cycle) x++;
            else      y++;
        }
    }
    cout<<x<<' '<<y;
}