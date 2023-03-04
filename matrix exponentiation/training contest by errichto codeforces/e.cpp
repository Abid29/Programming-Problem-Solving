#include <bits/stdc++.h>
using namespace std;
long long d = 65,md = 4294967296;

void matrix_mul(vector<vector<unsigned int>>&a,vector<vector<unsigned int>>&b){
    vector<vector<unsigned int>> ret(d,vector<unsigned int>(d,0));
    int row,col,k;
    for(row = 0; row < d; row++){
        for(col = 0;col < d; col++){
            for(k=0;k<d;k++){
                ret[row][col] += a[row][k]*b[k][col];
            }
        }
    }
    a = ret;
}

vector<vector<unsigned int>>matrix_ex(vector<vector<unsigned int>>&a,long long int n){
    vector<vector<unsigned int>>ret(d,vector<unsigned int>(d,0));
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
    long long int k;
    cin>>k; 
    vector<vector<unsigned int>>a(d,vector<unsigned int>(d,0));

    vector<pair<int,int>> moves = {{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};

    for(int i = 0;i < 8; i++){
        for(int j = 0;j < 8; j++){
            for(pair<int,int> p : moves){
                int row = i+p.first;
                int col = j+p.second;
                if(row<0 || row>7 || col<0 || col>7) continue;
                int u = row*8+col;
                int v = i*8+j;

                a[u][v] = a[v][u] = 1;
            }
        }
    }
    for(int i=0;i<65;i++) a[64][i] = 1;

    vector<vector<unsigned int>>a_n = matrix_ex(a,k+1);

    cout<<a_n[64][0];

}