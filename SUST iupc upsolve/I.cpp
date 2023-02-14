#include <bits/stdc++.h>
using namespace std;

int g[20][20] , cost[1<<15] , dp[1<<15][15] , c , inf = 2e9;
int vv[1<<15],bal[1<<15];

int f(int mask,int cc){
    if(mask==0||cc==c-1) return cost[mask];
    int &ret = dp[mask][cc];
    if(ret != -1) return ret;
    ret = inf;
    for(int ss=mask;ss>0;ss=(ss-1)&mask){
        ret = min(ret,max(cost[ss],f(mask^ss,cc+1)));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n , e , i , j;
    cin>>n>>c>>e;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            g[i][j] = -1;
        }
    }
    int u,v,w;
    for(i=1;i<=e;i++){
        cin>>u>>v>>w;
        g[u][v] = g[v][u] = w;
    }

    
    int tot = (1<<n);
    for(i=1;i<tot;i++) cost[i]=inf;

    
    int id=0;
    for(i=0;i<n;i++){
        cost[1<<i] = 0;
        vv[id++]=1<<i;
    }
    for(j=0;j<n;j++){
        int idd = 0;
        for(int k=0;k<id;k++){
            int val = vv[k];
            for(int x=0;x<n;x++){
                if(!(val&(1<<x))){
                    for(int y=0;y<n;y++){
                        if(val&(1<<y)){
                            //cout<<val << ' '<< x<< ' '<<y<<endl;
                            if(g[x][y]==-1) continue;
                            //cout<<val << ' '<< x<< ' '<<y<<endl;
                            if(cost[val|(1<<x)]==-1) cost[val|(1<<x)] = cost[val]+g[x][y];
                            else if(cost[val|(1<<x)]>cost[val]+g[x][y]) cost[val|(1<<x)]=cost[val]+g[x][y];
                            else continue;
                            bal[idd++]=val|(1<<x); 
                        }
                    }
                }
            }
        }
        id=idd;
        for(int k = 0;k<id;k++) vv[k] = bal[k];
    }
    //for(i=0;i<tot;i++){
    //    cout<<i<<' '<<cost[i]<<endl;
    //}
    memset(dp,-1,sizeof(dp));
	int ans = f(tot-1,0);
    //cout<<ans<<endl;
    if(ans >=  inf) ans = -1;
    cout<<ans<<endl;
}