#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long double>> g[100005];
long double dist[100005];
int path[100005];
int main(){
    int n,m;
    cin>>n>>m;
    int u,v,i;
    long double w;
    while(m--){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    long double r=100,l=0;
    while(r-l>0.0000001){
        long double mid = (l+r)/2.0;
        for(i=2;i<=n;i++){
            dist[i] = 1e9;
        }
        for(i=1;i<n;i++){
            for(auto it : g[i]){
                dist[it.first] = min(dist[it.first],dist[i]+(it.second-mid));
            }
        }
        if(dist[n]<=0) r=mid;
        else           l=mid;
    }
    //cout<<l<<' '<<r<<endl;
    for(i=2;i<=n;i++) dist[i] = 1e9;

    for(i=1;i<n;i++){
        for(auto it : g[i]){
            if(dist[it.first]>dist[i]+(it.second-r)){
                dist[it.first] = dist[i]+(it.second-r);
                path[it.first] = i;
            }
        }
    }

    stack<int>ans;
    ans.push(n);
    while(i>1){
        i=path[i];
        ans.push(i);
    }

    cout<<ans.size()-1<<'\n';
    while(ans.empty()==0){
        cout<<ans.top()<<' ';
        ans.pop();
    }
}