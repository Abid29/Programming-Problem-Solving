#include<bits/stdc++.h>
using namespace std;
#define sz 400010
int n, k, m, l[sz], r[sz], ord[sz], cls[sz];
int nord[sz], ncls[sz], cnt[sz];
vector<pair<pair<int,int>,int>> vv;

void countingSort(){
    for(int i = 0;i < n;i++) cnt[i] = 0;
    for(int i = 0;i < n;i++) cnt[cls[i]]++;
    for(int i = 1;i < n;i++) cnt[i] += cnt[i-1];  
    for(int i=n-1;i>=0;i--){
        int idx = (ord[i]+n-(1<<k))%n;
        nord[--cnt[cls[idx]]] = idx;
    }

    for(int i = 0;i < n;i++) ord[i] = nord[i];
}

void updateClass(){
    ncls[ord[0]] = 0;
    pair<int,int> prev, now;
    prev = {cls[ord[0]],cls[(ord[0]+(1<<k))%n]};
    for(int i = 1;i < n;i++){
        now = {cls[ord[i]],cls[(ord[0]+(1<<k))%n]};
        if(now == prev) ncls[ord[i]] = ncls[ord[i-1]];
        else            ncls[ord[i]] = ncls[ord[i-1]] + 1; 
    }

    for(int i = 0;i < n;i++) cls[i] = ncls[i];
}

int main(){
    string s; cin>>s; s += '$';
    n = s.size(); cin >> m;
    for(int i = 0;i < m; i++){
        cin>>l[i]>>r[i]; l[i]-- , r[i]--;
        vv.push_back({{-r[i] + l[i],-l[i]},i});
    }

    for(char ch : s) cnt[ch] ++;
    cnt['$'] = 0;
    for(int i=1;i<124;i++) cnt[i] += cnt[i-1];

    for(int i = 0;i < n;i++) ord[cnt[s[i]]--] = i;

    cls[ord[0]] = 0;
    for(int i = 1;i < n;i++){
        if(s[ord[i]] == s[ord[i-1]]) cls[ord[i]] = cls[ord[i-1]];
        else                         cls[ord[i]] = cls[ord[i-1]] + 1;
    }

    while((1<<k) < n){
        countingSort();
        updateClass();
        k++;
    }

    /*for(int i = 0;i < n;i++){
        cout<<i<<' '<<cls[i]<<endl;
    }*/

    sort(vv.begin(),vv.end());
    vector<int>sorted;
    for(int i = 0;i < m;i++){
        sorted.push_back(cls[l[i]]);
    }
    sort(sorted.begin(),sorted.end());
    vector<int>ans(m+5);
    for(auto ii : vv){
        //cout<<ii.first.first<<' '<<ii.second<<endl;
        int id = lower_bound(sorted.begin(),sorted.end(),cls[l[ii.second]])-sorted.begin();
        cout<<l[ii.second]<<' '<<id<<' '<<ii.second<<endl;
        ans[id] = ii.second;
    }
    for(int i = 0;i < m;i++){
        cout<<l[ans[i]]+1<<' '<<r[ans[i]]+1<<endl;
    }

}