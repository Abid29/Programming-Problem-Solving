#include<bits/stdc++.h>
using namespace std;
int p[100100],a[100100],pos[100100];
int main(){
    int t;cin>>t;while(t--){
        int n,m,d,i,j;
        cin>> n>>m>>d;
        for(i=1;i<=n;i++){
            cin>>p[i]; pos[p[i]] = i;
        }
        for(i=1;i<=m;i++) cin>>a[i];
        int mx = 1e7;
        for(i=2;i<=m;i++){
            if(pos[a[i]]>pos[a[i-1]] && pos[a[i-1]]+d>=pos[a[i]]){
                int val;
                if(d>=n-1) val = 1e5;
                else         val = pos[a[i-1]]+d+1-pos[a[i]];
                mx = min(mx,min(-pos[a[i-1]]+pos[a[i]],val));
            }
            else{
                mx = 0;break;
            }
        }
        cout<<mx<<endl;
    }
}