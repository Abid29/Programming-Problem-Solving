#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n; cin>>n;
        vector<int>cnt(n+5,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<=n) cnt[a[i]]++;
        }
        
        int i=0;
        if(cnt[0] <= (n+1)/2){
            cout<<0<<endl;
        }
        else if(cnt[1]==0||n-cnt[1]-cnt[0]>0){
            cout<<1<<endl;
        }
        else cout<<2<<endl;



    }
}