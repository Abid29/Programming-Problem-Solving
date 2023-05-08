#include <bits/stdc++.h>
using namespace std;
multiset<pair<long long,long long>>hh,ww;

bool check(long long h,long long w){
    //cout<<h<<' '<<w<<endl;
    multiset<pair<long long,long long>>hhh = hh;
    multiset<pair<long long,long long>>www = ww;
    while(hhh.size()>1){
        //cout<<hhh.size()<<endl;
        auto itt = hhh.lower_bound({h,0});
        pair<long long,long long>it = *itt;
        if(itt != hhh.end()&&(it).first==h && (it).second<w){
            www.erase(www.find({it.second,it.first}));
            w -= (it).second;
            hhh.erase(hhh.lower_bound({h,0}));
            continue;
        }
        itt = www.lower_bound({w,0});
        it = *itt;
        if(itt != www.end()&&it.first==w && it.second<h){
            hhh.erase(hhh.find({it.second,it.first}));
            h -= it.second;
            www.erase(www.lower_bound({w,0}));
            continue;
        }
        return 0;
    }

    pair<long long,long long>it = *hhh.begin();

    if(h==it.first&&w==it.second) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--){
        long long int n,h,w;
        cin >> n;

        long long area = 0,mxh=0,mxw=0;
        hh.clear(),ww.clear();
        
        for(int i=0;i<n;i++){
            cin >> h >> w;
            hh.insert({h,w});
            ww.insert({w,h});
            area += w*h;
            mxh = max(mxh,h);
            mxw = max(mxw,w);
        }
        //cout<<hh.size()<<endl;

        //cout<<area<<' '<<mxh<<' '<<mxw<<endl;

        set<pair<long long,long long>>ans;
        if(area%mxh == 0 && check(mxh,area/mxh)) ans.insert({mxh,area/mxh});
        if(area%mxw == 0 && check(area/mxw,mxw)) ans.insert({area/mxw,mxw});
        cout<<ans.size()<<'\n';
        for(auto it : ans) cout<<it.first<<' '<<it.second<<'\n';
    }
}