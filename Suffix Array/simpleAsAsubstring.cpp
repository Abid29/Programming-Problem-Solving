#include<bits/stdc++.h>
using namespace std;
#define sz 1000055
int n, m, k, l[12], r[12], where[sz], lcp[sz];
string text="";
int cnt[sz], ord[sz], cls[sz], nord[sz], ncls[sz];

void countingSort(){
    for(int i=0;i<n;i++) cnt[i] = 0;
    for(int i=0;i<n;i++) cnt[cls[i]] ++;
    for(int i=1;i<n;i++) cnt[i] += cnt[i-1];

    for(int i=n-1;i>=0;i--){
        int idx = (ord[i]+n-(1<<k))%n;
        nord[--cnt[cls[idx]]] = idx;
    }

    for(int i = 0;i < n;i ++) ord[i] = nord[i];
}

void updateClass(){
    ncls[ord[0]] = 0;
    pair<int,int>prev, now;
    prev = {cls[ord[0]] , cls[(ord[0]+(1<<k))%n]};
    for(int i=1;i<n;i++){
        now = {cls[ord[i]] , cls[(ord[i]+(1<<k))%n]};

        if(now == prev) ncls[ord[i]] = ncls[ord[i-1]];
        else            ncls[ord[i]] = ncls[ord[i-1]] + 1;

        prev = now;
    }

    for(int i=0;i<n;i++) cls[i] = ncls[i];
}

int main(){
    cin >> m;
    string s;
    for(int i=0;i<m;i++){
        cin >> s;
        s+=('Z'-i);
        //cout<<s<<endl;
        l[i] = text.size();
        text += s;
        r[i] = text.size()-1;
    }

    n = text.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>=l[j] && i<=r[j]) where[i] = j;
        }
    }

    for(char ch : text) cnt[ch] ++;

    cnt[('Z'-m+1)] = 0;
    for(int i=1;i<125;i++) cnt[i] += cnt[i-1];

    for(int i=0;i<n;i++){
        ord[cnt[text[i]]]=i;
        //cout<<i<<' '<<text[i]<<' '<<cnt[text[i]]<<endl;
        cnt[text[i]]--;
    }

    cls[ord[0]] = 0;
    for(int i=1;i<n;i++){
        if(text[ord[i]] == text[ord[i-1]]) cls[ord[i]] = cls[ord[i-1]];
        else                               cls[ord[i]] = cls[ord[i-1]] + 1;
    }

    /*for(int i =0;i< n;i++) cout<<ord[i]<<' ';
    cout<<endl;*/

    while((1<<k) < n){
        countingSort();
        updateClass();
        k++;
    }

    /*
    for(int i =0;i< n;i++) cout<<cls[i]<<' ';
    cout<<endl;

    for(int i =0;i< n;i++) cout<<ord[i]<<' ';
    cout<<endl;*/

    int len = 0;
    for(int i = 0;i < n-1; i++){
        int j = ord[(cls[i]-1)];
        while(text[i+len] == text[j+len]) len++;
        lcp[i] = len; len = max(0,len-1);
    }

    int ans = 0;
    
    for(int i=1;i<n;i++){
        int mn = lcp[ord[i]];

        //cout<<i<<' '<<ord[i]<<' '<<mn<<endl;
        
        bitset<12>bb;
        
        //cout<<where[ord[i]]<<endl;
        bb[where[ord[i]]] = 1;
        if(bb[where[ord[i-1]]]) continue;
        bb[where[ord[i-1]]]=1;

        int j;
        for(j=1;j<m-1;j++){
            if(i+j>=n) break;
            int id = ord[i+j];
            //cout<<id<<endl;
            if(bb[where[id]]==0) bb[where[id]] = 1;
            else                 break;

            mn = min(mn , lcp[id]);
        }
        if(j!=m-1) continue;
        //cout<<"abid"<<endl;
        if(i>1 && lcp[ord[i-1]]>=mn) continue;
        
        //cout<<"abiid"<<endl;
        if(i+m-1<n && lcp[ord[i+m-1]]>=mn) continue;

        //cout<<i<<' '<<mn<<endl;
        //cout<<lcp[ord[i-1]]<<endl;
        //cout<<i+m<<' '<<lcp[ord[i+m]]<<endl;
        ans = max(ans,mn);

    }
    cout<<ans<<endl;
}