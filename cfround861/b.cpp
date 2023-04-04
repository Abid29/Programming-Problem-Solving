#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t; while(t--){
        int n,m,i,j;
        cin>>n>>m;
        vector<vector<long long>>a(m,vector<long long>(n));

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[j][i];
            }
        }

        for(i=0;i<m;i++){
            sort(a[i].begin(),a[i].end());
        }

        long long ans = 0;

        for(j=0;j<m;j++){
            long long psum=0,ssum = 0;
            for(i=0;i<n;i++){
                ssum+=a[j][i];
            }

            for(i=0;i<n;i++){
                ssum -= a[j][i];
                ans += (a[j][i]*i - psum) + (ssum - a[j][i]*(n-i-1));
                psum += a[j][i];
            }

        }
        cout<<ans/2<<endl;
    }
}