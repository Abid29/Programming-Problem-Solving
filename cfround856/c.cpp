#include <bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,i;
        cin>>n;
        for(i=1;i<=n;i++) cin>>a[i];
        int l=1,r=1;
        cout<<1;
        for(i=2;i<=n;i++){
            r++;
            int cnt = r-l+1;
            while(cnt>1 && cnt > a[l]) l++,cnt--;
            cout<<' '<<r-l+1;
        }
        cout<<'\n';
    }
    return 0;
}