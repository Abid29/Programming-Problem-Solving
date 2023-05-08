#include <bits/stdc++.h>
using namespace std;
#define mx 100005
int p[mx],r[35],mex[35],grundy[mx];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--){
        int n,m;
        cin >> n >> m;

        for(int i=0;i<m;i++) cin>>r[i];
        for(int i=0;i<n;i++) cin>>p[i];

        for(int i=1;i<mx;i++){
            for(int j=0;j<=m;j++) mex[j] = 0;
            for(int j=0;j<m;j++){
                if(r[j] > i) continue;
                mex[grundy[i-r[j]]] = 1;
            }
            for(int j=0;j<=m;j++){
                if(mex[j] == 0){
                    grundy[i] = j; break;
                }
            }
        }

        int ans = 0;
        for(int i = 0;i < n;i++) ans ^= grundy[p[i]];

        if(ans == 0) cout<<"Vinit\n";
        else         cout<<"Ada\n";
    }
}