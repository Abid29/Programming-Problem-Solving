#include <bits/stdc++.h>
using namespace std;
long long d,INF = 2e18+5;

void matrix_mul(vector<vector<long long>>&a,vector<vector<long long>>&b){
    vector<vector<long long>> ret(d,vector<long long>(d,INF));
    int row,col,k;
    for(row = 0; row < d; row++){
        for(col = 0;col < d; col++){
            for(k=0;k<d;k++){
                ret[row][col] = min(ret[row][col],a[row][k]+b[k][col]);
            }
        }
    }
    a = ret;
}

vector<vector<long long>>matrix_ex(vector<vector<long long>>&a,long long int n){
    vector<vector<long long>>ret(d,vector<long long>(d,0));
    //for(int i = 0;i < d;i++) ret[i][i] = 1;

    while(n>0){
        if(n&1) matrix_mul(ret,a);
        n/=2 ,  matrix_mul(a,a);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n,m,k;
    cin>>n>>m>>k; d = n;
    vector<vector<long long>>a(n,vector<long long>(n,INF));

    while(m--){
        int u,v,c; cin>>u>>v>>c;
        a[u-1][v-1] = c;
    }

    vector<vector<long long>>a_n = matrix_ex(a,k);

    long long ans = INF;

    for(vector<long long> v : a_n){
        for(long long it : v) ans = min(ans,it);
    }
    if(ans > 1e18){
        cout<<"IMPOSSIBLE"; return 0;
    }
    cout<<ans<<'\n';
}