#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b>d || (c-a)>(d-b)){
            cout<<"-1\n";
        }
        else{
            int ans = d-b;
            c= c-(d-b);
            ans += abs(c-a);
            cout<<ans<<endl;
        }
    }
}