#include<bits/stdc++.h>
using namespace std;
int query(int x){
    cout<<"- "<<x<<'\n';
    cout.flush(); int k;
    cin>>k; return k;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;while(t--){

        int tot , ans = 0 , cur , x = 0;
        cin>>tot; cur = tot;
        while(tot){
            cur = query(1<<x);
            x = cur - tot + 1;
            ans |= (1<<x);
            tot--;
        }
        cout<<"! "<<ans<<'\n';
        cout.flush();
    }
}