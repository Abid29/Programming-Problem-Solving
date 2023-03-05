#include <bits/stdc++.h>
using namespace std;
long long d,s,t,md = 1e9+7;

vector<vector<long long>>a[32];

void matrix_mul(vector<vector<long long>>&cur,int i){
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
    a[i+1] = ret;
}

void matrix_ex(long long int k){
    vector<long long>row(d,1);
    
    int cnt = 0,bit[2],i,j;
    for(i=0,j=0;i<30;i++){
        if(k & (1<<i)){
            cnt++,bit[j++] = i;
            if(cnt==2) break;
        }
    }
    if(i==30){
        cout<<a[bit[0]][s][t]<<'\n';return;
    }

    for(int i = 0;i < d;i++) row[i]= a[bit[0]][s][i];

    for(++i;i<30;i++){
        if(k & (1<<i)){
            vector<long long>newrow(d,0);
            for(int x=0;x<d;x++){
                for(int y=0;y<d;y++){
                    newrow[x] = (newrow[x]+row[y]*a[i][y][x])%md;
                }
            }
            row = newrow;
        }
    }
    long long ans = 0;
    for(int x=0;x<d;x++){
        ans = (ans+row[x]*a[bit[1]][x][t])%md;
    }
    cout<<ans<<'\n';
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
        matrix_mul(a[i-1],i-1);
    }

    while(q--){
        int k;
        cin>>s>>t>>k; s--,t--;
        matrix_ex(k);
    }
}