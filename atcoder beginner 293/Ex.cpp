#include <bits/stdc++.h>
using namespace std;
vector<int>tree[200010];

int dfs(int u,int par){
    if(tree[u].size()==1 && par!=0) return 1;
    vector<int>nw;
    for(int v : tree[u]){
        if(v == par) continue;
        nw.push_back(dfs(v,u));
    }
    sort(nw.begin(),nw.end());
    cout<<u<<' '<<par<<"u and par\n";
    for(int it : nw) cout<<it<<' ';
    cout<<endl;
    if(nw.size()==1) return nw.back()-1;
    else{
        int last = nw.back();
        nw.pop_back();
        if(last == nw.back()) return last;
        else                  return last-1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    cin>>n;
    for(i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int leaf;
    for(i=1;i<=n;i++){
        if(tree[i].size()==1){
            leaf = i;break;
        }
    }
    cout<<leaf<<endl;
    cout<<dfs(leaf,0)+1<<endl;
}