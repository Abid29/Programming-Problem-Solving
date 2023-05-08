#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int i,n,ans = 0;
        string s;
        cin>>s;
        n=s.size();
        for(i=1;i<n;i++){
            if(s[i] == '_'&&s[i-1]=='_') ans++;
        }
        if(s[0]=='_') ans++;
        if(s[n-1]=='_') ans++;
        if(n==1&&s[0]=='^') ans=1;
        cout<<ans<<endl;

    }
}