#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,m,i,j;
        cin>>n>>m;
        cout<<n*m<<'\n';
        long long sum = 0;
        for(i=1;i<=n;i++){
            for(j=0;j<m;j++){
                cout<<sum+j<<' ';
            }
            cout<<'\n';
            sum+= 256;
        }
        cout<<'\n';
    }
}