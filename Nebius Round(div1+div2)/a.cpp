#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int a,b;
        cin>>a>>b;
        a=abs(a),b=abs(b);
        int ans = 2*max(a,b)-1;
        ans += (a==b);
        cout<<ans<<endl;
    }
    return 0;
}