#include<bits/stdc++.h>
using namespace std;
int n,k, ord[100100], cls[100100];
int nord[100100], cnt[100100], ncls[100100];

void countingSort(){
    for(int i=0;i<n;i++) cnt[i] = 0;

    for(int i=0;i<n;i++) cnt[cls[i]] ++;

    for(int i=1;i<n;i++) cnt[i] += cnt[i-1];

    for(int i=n-1;i>=0;i--){
        int idx = (ord[i]-(1<<k)+n) % n;
        nord[--cnt[cls[idx]]] = idx;
    }

    for(int i=0;i<n;i++) ord[i] = nord[i];

}

void classUpdate(){
    ncls[ord[0]] = 0;

    pair<int,int>prev,now;
    prev = {cls[ord[0]] , cls[(ord[0]+(1<<k))%n]};

    for(int i = 1;i < n;i ++){
        now = {cls[ord[i]] , cls[(ord[i]+(1<<k))%n]};

        if(prev == now) ncls[ord[i]] = ncls[ord[i-1]];
        else            ncls[ord[i]] = ncls[ord[i-1]] + 1;

        prev = now;
    }

    for(int i=0;i<n;i++) cls[i] = ncls[i];
}

int main(){
    string s; cin >> s; s += '$';
    int i;  n = s.size();

    for(char ch : s) cnt[ch]++;
    cnt['$'] = 0;

    for(i=1;i<125;i++) cnt[i] += cnt[i-1];

    // order array contains index of suffix in sorted ascending


    for(i=0;i<n;i++) ord[cnt[s[i]]--] = i; 

    int cc = 0; cls[ord[0]] = cc;

    for(i=1;i<n;i++){
        if(s[ord[i]] == s[ord[i-1]])     cls[ord[i]] = cc;
        else                             cls[ord[i]] = ++cc;
    }
    //for(i=0;i<n;i++) cout<<cls[i]<<"   "; 

    while((1<<k) < n){
        countingSort();
        classUpdate();
        k++;
    }

    for(i=0;i<n;i++) cout<<ord[i]<<' ';
}