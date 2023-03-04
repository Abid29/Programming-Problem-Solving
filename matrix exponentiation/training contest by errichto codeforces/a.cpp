#include <bits/stdc++.h>
using namespace std;
int d = 2;

vector<vector<long double>>matrix_mul(vector<vector<long double>>&a,vector<vector<long double>>&b){
    vector<vector<long double>> ret(2,vector<long double>(2,0));
    int row,col,k;
    for(row = 0; row < d; row++){
        for(col = 0;col < d; col++){
            for(k=0;k<d;k++){
                ret[row][col] += a[row][k]*b[k][col];
            }
        }
    }
    return ret;
}

vector<vector<long double>>matrix_ex(vector<vector<long double>>&a,int n){
    vector<vector<long double>>ret = {{1,0},{0,1}};

    while(n>0){
        if(n&1) ret = matrix_mul(ret,a);
        n/=2 , a = matrix_mul(a,a);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long double p,q;
    int n;
    cin>>n>>p;
    q = 1.00-p;
    vector<vector<long double>>a={{q,p},{p,q}};

    vector<vector<long double>>a_n = matrix_ex(a,n);

    long double ph=a_n[0][0];

    cout<<fixed<<setprecision(10)<<ph<<'\n';
}