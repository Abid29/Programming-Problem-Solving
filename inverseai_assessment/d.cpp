#include <bits/stdc++.h>
using namespace std;
int f[200100] , c[200100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++) cin >> f[i];
        for(int i=0;i<n;i++) cin >> c[i];
        for(int i=0;i<n;i++) v.push_back(make_pair(c[i],f[i]));

        sort(v.begin(),v.end());

        long long ans = 0;

        for(pair<int,int>p : v){
            long long mn = min(n,p.second);
            n -= mn, ans += mn*p.first;
            if(n == 0) break;
        }

        cout<<ans<<'\n';
    }
}