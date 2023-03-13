#include <bits/stdc++.h>
using namespace std;
int ti[200010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,k,d,w,i;
        cin>>n>>k>>d>>w;
        for(i=0;i<n;i++){
            cin>>ti[i];
        }
        sort(ti,ti+n);
        int id = 0, ans = 0;
        while(id<n){
            int last = ti[id]+w+d,cnt=0;
            ans++;
            while(cnt<k&&id<n){
                if(ti[id] <= last){
                    cnt++,id++;
                }
                else break;
            }
        }
        cout<<ans<<endl;
    }
}