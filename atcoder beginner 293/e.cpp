#include <bits/stdc++.h>
using namespace std;
long long d = 2,md;

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
    long long A,x;
    cin>>A>>x>>md;
    vector<vector<long long>>a = {{A,0},{1,1}};
    vector<vector<long long>>b = matrix_ex(a,x);
    cout<<b[1][0];
}

