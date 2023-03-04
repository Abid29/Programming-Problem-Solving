#include <bits/stdc++.h>
using namespace std;
long long d = 2,md = 1e9+7;

vector<vector<long long>>matrix_mul(vector<vector<long long>>&a,vector<vector<long long>>&b){
    vector<vector<long long>> ret(d,vector<long long>(d,0));
    int row,col,k;
    for(row = 0; row < d; row++){
        for(col = 0;col < d; col++){
            for(k=0;k<d;k++){
                ret[row][col] += a[row][k]*b[k][col];
            }
            ret[row][col]%=md;
        }
    }
    return ret;
}

vector<vector<long long>>matrix_ex(vector<vector<long long>>&a,long long int n){
    vector<vector<long long>>ret = {{1,0},{0,1}};

    while(n>0){
        if(n&1) ret = matrix_mul(ret,a);
        n/=2 , a = matrix_mul(a,a);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n;
    cin>>n;
    vector<vector<long long>>a={{1,1},{1,0}};

    vector<vector<long long>>a_n = matrix_ex(a,n);

    
    cout<<a_n[1][0]<<'\n';
}