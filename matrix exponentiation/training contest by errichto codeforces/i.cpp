#include <bits/stdc++.h>
using namespace std;
long long d,s,t,md = 1e9+7;

vector<vector<long long>>a[32];

vector<vector<long long>> matrix_mul(vector<vector<long long>>&cur,int i){
    vector<vector<long long>> ret(d,vector<long long>(d,0));
    int row,col,k;
    for(row = 0; row < d; row++){
        for(col = 0;col < d; col++){
            for(k=0;k<d;k++){
                ret[row][col] += cur[row][k]*a[i][k][col];
                ret[row][col]%=md;
            }
        }
    }
    return ret;
}

void matrix_ex(long long int k){
    vector<vector<long long>>ret(d,vector<long long>(d,0));
    for(int i = 0;i < d;i++) ret[i][i] = 1;

    for(int i=0;i<30;i++){
        if((1<<i)&k){
            ret = matrix_mul(ret,i);
        }
    }

    cout<<ret[s][t]<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q; d = n;

    a[0].resize(d,vector<long long>(d,0));

    while(m--){
        int u,v;
        cin>>u>>v; u--,v--;
        a[0][u][v] = 1;
    }

    for(int i=1;i<30;i++){
        a[i] = matrix_mul(a[i-1],i-1);
    }

    while(q--){
        int k;
        cin>>s>>t>>k; s--,t--;
        matrix_ex(k);
    }
}