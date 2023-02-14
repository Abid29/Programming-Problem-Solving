#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int t;cin>>t;while(t--){
        int n,i;
        long long sum = 0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i]; sum+=a[i];
        }
        long long cur = 0;
        long long ans = 0;
        for(i=0;i<n-1;i++){
            cur += a[i];
            ans = max(ans,__gcd(cur,sum-cur));
        }
        cout<<ans<<endl;
    }
}