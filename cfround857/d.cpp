#include <bits/stdc++.h>
using namespace std;
int a[500100],b[500100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,i;
        cin>>n;
        multiset<int>allb,curb;
        vector<pair<int,int>>vv;
        for(i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            vv.push_back({a[i],i});
            allb.insert(b[i]);
        }
        sort(vv.begin(),vv.end());

        int ans = 2e9;
        for(i=0;i<n;i++){

            allb.erase(allb.find(b[vv[i].second]));
            
            if(i<n-1) ans = min(ans,abs(*allb.rbegin()-vv[i].first));
            //cout<<ans<<endl;

            if(i<n-1&&*allb.rbegin()==vv[i].first){
                break;
            }
            //cout<<*allb.rbegin()<<endl;
            if(i==n-1||(*allb.rbegin()<vv[i].first)){
                if(curb.empty()){
                    curb.insert(b[vv[i].second]);
                    continue;
                }
                if(curb.lower_bound(vv[i].first)!=curb.end()){
                    ans = min(ans,abs(vv[i].first-*curb.lower_bound(vv[i].first)));
                    //cout<<ans<<"p\n";
                }
                if(curb.lower_bound(vv[i].first)!=curb.begin()){
                    auto it = curb.lower_bound(vv[i].first);
                    int val = *(--it);
                    ans = min(ans,abs(vv[i].first-val));
                    //cout<<ans<<"p\n";
                }
            }
            curb.insert(b[vv[i].second]);
        }


        cout<<ans<<endl;
    }
}