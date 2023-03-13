#include <bits/stdc++.h>
using namespace std;
int a[200010],l[200010],r[200010];
long long ans[200010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q,i;
    cin>>n>>q;
    for(i=1;i<=n;i++) cin>>a[i];
    vector<pair<int,int>>v;
    for(i=1;i<=q;i++){
        cin>>l[i]>>r[i];
        v.push_back({l[i],i});
    }
    sort(v.begin(),v.end());

    int B = n/sqrt(q),id=0;
    if(B==0) B=1;

    int ll=0,rr=1;
    long long can=0;
    vector<int>cnt(200005,0);
    for(int totB = 0;totB<n;){
        totB+=B;
        vector<pair<int,int>>vv;
        while(id<q&&v[id].first <= min(n,totB)){
            i=v[id].second;
            //cout<<"i = "<<i<<endl;
            vv.push_back({r[i],i});
            id++;
        }
        sort(vv.begin(),vv.end());
        
        for(pair<int,int>p : vv){
            //cout<<p.second<<' ';
            int L=l[p.second],R=p.first;
            while(rr<=R){
                long long val = cnt[a[rr]];
                if(val>1){
                    can+=(val-1)*val/2;
                }
                cnt[a[rr++]]++;
            }
            while(rr>R+1){
                cnt[a[--rr]]--;
                long long val = cnt[a[rr]];
                if(val>1){
                    can-=(val-1)*val/2;
                }
            }
            while(ll<L){
                long long val = --cnt[a[ll++]];
                if(val>1){
                    can-=(val-1)*val/2;
                }
            }
            while(ll>L){
                long long val = cnt[a[--ll]];
                if(val>1){
                    can += val*(val-1)/2;
                }
                cnt[a[ll]]++;
            }
            ans[p.second] = can;
            //cout<<can<<endl;
        }

    }
    for(i=1;i<=q;i++) cout<<ans[i]<<'\n';
}