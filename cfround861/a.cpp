#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;while(t--){
        int l,r;
        cin>>l>>r;
        
        r = min(r,l+100);
        int ans = -1,val;
        for(int i =l;i<=r;i++){
            int mn = 9,mx = 0;
            int c = i;
            while(c>0){
                mn = min(mn,c%10);
                mx = max(mx,c%10);
                c/=10;
            }

            if(ans<mx-mn){
                ans = mx-mn;
                val = i;
            }
        }
        cout<<val<<endl;
    }
}