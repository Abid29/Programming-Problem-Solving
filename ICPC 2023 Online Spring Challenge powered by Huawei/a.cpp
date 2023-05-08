#include <bits/stdc++.h>
using namespace std;
int L[15],D[15],Qmn[15],Qmx[15],Qbs[15];
vector<pair<int,int>>v;
int sz[15],ind[15][1000005];
pair<int,int>mem[1000005];
set<int>pos[15];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,Q;
    cin >> N >> Q >> M;
    for(int i=1;i<=N;i++) {cin>> L[i];v.push_back({L[i],i});} 
    for(int i=1;i<=N;i++) cin>> D[i];

    for(int i=1;i<=N;i++){
        cin>> Qmn[i] >> Qbs[i]>> Qmx[i];
    }

    int i = 1;
    while(i<=Q&&M--){
        int u,p;
        cin >> u >> p;

        if(pos[u].find(ind[u][p]) == pos[u].end()){
            if(pos[u].size() == Qmx[u]){
                int ni = *pos[u].begin();
                ind[mem[ni].first][mem[ni].second] = 0;
                mem[ni] = {u,p};
                ind[u][p] = ni;
                cout<<ni<<endl;
                cout.flush();
                continue;
            }

            pos[u].insert(i);
            ind[u][p] = i;
            mem[i] = {u,p};
            cout<<i<<endl;
            cout.flush();i++;
        }
        else{
            cout<<ind[u][p]<<endl;
            cout.flush();
        }
    }

    sort(v.begin(),v.end());
    //reverse(v.begin(),v.end());

    //cout<<M<<endl;

    while(M-->0){
        //cout<<"badi";
        int u,p;
        cin>> u >> p;
        if(pos[u].find(ind[u][p]) == pos[u].end()){
            if(pos[u].size() == Qmx[u]){
                int ni = *pos[u].begin();
                ind[mem[ni].first][mem[ni].second] = 0;
                mem[ni] = {u,p};
                ind[u][p] = ni;
                cout<<ni<<endl;
                cout.flush();
                continue;
            }
            for(auto it : v){
                if(it.second == u && pos[u].size()>=Qmn[u]){
                    int ni = *pos[u].begin();
                    ind[mem[ni].first][mem[ni].second] = 0;
                    mem[ni] = {u,p};
                    ind[u][p] = ni;
                    cout<<ni<<endl;
                    cout.flush();
                    break;
                }
                else if(pos[it.second].size()>Qmn[it.second]){
                    int ni = *pos[u].begin();
                    ind[mem[ni].first][mem[ni].second] = 0;
                    mem[ni] = {u,p};
                    ind[u][p] = ni;
                    cout<<ni<<endl;
                    cout.flush();
                    break;
                }
            }
        }
        else{
            cout<<ind[u][p]<<endl;
            cout.flush();
        }
    }
}