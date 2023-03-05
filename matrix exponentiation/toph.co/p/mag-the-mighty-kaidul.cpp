#include <bits/stdc++.h>
using namespace std;
long long d,md = 1717171769;

void matrix_mul(vector<vector<long long>>&a,vector<vector<long long>>&b){
    vector<vector<long long>> ret(d,vector<long long>(d,0));
    int row,col,k;
    for(row = 0; row < d; row++){
        for(col = 0;col < d; col++){
            for(k=0;k<d;k++){
                ret[row][col] += a[row][k]*b[k][col];
                ret[row][col]%=md;
            }
        }
    }
    a = ret;
}

vector<vector<long long>>matrix_ex(vector<vector<long long>>&a,long long int n){
    vector<vector<long long>>ret(d,vector<long long>(d,0));
    for(int i = 0;i < d;i++) ret[i][i] = 1;

    while(n>0){
        if(n&1) matrix_mul(ret,a);
        n/=2 ,  matrix_mul(a,a);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int l,n;
    cin>>l>>n; d = n, l--;
    vector<vector<long long>>a(n,vector<long long>(n,0));

    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    vector<vector<long long>>a_n = matrix_ex(a,l);

    long long ans = 0;

    for(vector<long long> v : a_n){
        for(long long it : v) ans += it;
    }
    ans %= md;
    cout<<ans<<'\n';
}