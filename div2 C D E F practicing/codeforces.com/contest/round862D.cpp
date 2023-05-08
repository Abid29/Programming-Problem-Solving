#include <bits/stdc++.h>
using namespace std;
vector<int>tree[100005];
int dist[100005], cnt[100005], dis, node;

void farthest(int u , int p, int dep){
    if(p && tree[u].size()==1){
        if(dep > dis) dis = dep, node = u;
    }

    for(int v : tree[u]){
        if(v == p) continue;
        farthest(v,u,dep+1);
    }
}

void dfs_dist(int u, int p, int dep){
    dist[u] = max(dist[u] , dep);
    for(int v : tree[u]){
        if(v == p) continue;
        dfs_dist(v,u,dep+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,u,v,i;
    cin >> n;
    for(i = 1;i < n; i++){
        cin >> u >>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dis = 0;
    farthest(1,0,0);
    u = node;
    dis = 0;
    farthest(u,0,0);
    v = node;

    //cout<<u <<' '<<v<<endl;

    dfs_dist(u,0,0);
    dfs_dist(v,0,0);

    for(i = 1; i <= n; i++){
        cnt[dist[i]]++;
    }

    stack<int>ans;
    i=n;
    while(cnt[i] == 0) {ans.push(n); i--;}
    int sum = cnt[i--];
    //cout<<i+1<<"  "<<sum<<endl;
    while(cnt[i]){ans.push(n-sum+1);sum+=cnt[i--];}
    ans.push(n-sum+1);
    while(ans.size() < n) ans.push(1);
    while(ans.empty()==0){
        cout<< ans.top()<<' ';
        ans.pop();
    }

}