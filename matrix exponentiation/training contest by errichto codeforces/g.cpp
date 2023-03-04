#include <bits/stdc++.h>
using namespace std;
long long d,md = 1e9+7;

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
    long long int n,m,k,x[15],c[15];
    cin>>n>>k; d = n+3;
    for(int i=n-1;i>=0;i--) cin>>x[i];
    x[n]=1,x[n+1]=n,x[n+2] = n*n;
    for(int i=0;i<d;i++) cin>>c[i];
    if(k<n){
        cout<<x[n-1-k]; return 0;
    }
    k -= n-1;

    vector<vector<long long>>a(d,vector<long long>(d,0));

    for(int i=0;i<d;i++){
        a[0][i] = c[i];
    }
    for(int i=1;i<n;i++){
        a[i][i-1] = 1;
    }
    a[n][n]=a[n+1][n]=a[n+1][n+1]=a[n+2][n]=a[n+2][n+2]=1;
    a[n+2][n+1] = 2;

    

    vector<vector<long long>>a_n = matrix_ex(a,k);

    long long ans = 0;

    for(int i=0;i<d;i++){
        ans = (ans+a_n[0][i]*x[i])%md;
    }
    
    cout<<ans<<'\n';
}