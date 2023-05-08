#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;while(t--){
        string s;
        cin>>s;
        long long i,n=s.size(),cnt=0,tot=0,ans=0;
        for(char ch : s){
            if(ch=='1') cnt++;
            else        cnt=0;
            tot = max(tot,cnt);
        }
        if(cnt&&cnt!=n){
            for(char ch : s){
                if(ch=='0') break;
                cnt++;
            }
        }
        tot=max(tot,cnt);
        if(tot == n) ans = tot*tot;
        else         ans = tot;
        for(i=1;i<=tot/2;i++){
            ans = max(ans,(tot-i)*(i+1));
        }
        cout<<ans<<endl;
    }
}