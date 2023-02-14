#include<bits/stdc++.h>
using namespace std;
#define sz 400005 
int cnt[sz], ord[sz], cls[sz];
int k, nord[sz], ncls[sz];
long long n;
int lcp[sz];

void countingSort(){
    for(int i=0;i<n;i++) cnt[i] = 0;
    for(int i=0;i<n;i++) cnt[cls[i]] ++;

    for(int i=1;i<n;i++) cnt[i] += cnt[i-1];

    for(int i = n-1; i>=0; i--){
        int idx = (ord[i]-(1<<k)+n)%n;
        nord[--cnt[cls[idx]]] = idx;
    }

    for(int i = 0;i < n;i++) ord[i] = nord[i];
}

void updateClass(){
    ncls[ord[0]] = 0;
    pair <int,int> prev, now;
    prev = {cls[ord[0]], cls[(ord[0]+(1<<k))%n]};

    for(int i=1;i<n;i++){
        now = {cls[ord[i]], cls[(ord[i]+(1<<k))%n]};
        if(now == prev) ncls[ord[i]] = ncls[ord[i-1]];
        else            ncls[ord[i]] = ncls[ord[i-1]]+1; 
        prev = now;
    }

    for(int i=0;i<n;i++) cls[i] = ncls[i];
}

int main(){
    string s; cin >> s;
    s+='$'; n = s.size();

    for(char ch : s) cnt[ch] ++;

    cnt['$'] = 0;
    for(int i=1;i<130;i++) cnt[i] += cnt[i-1];

    //cout<<cnt['$']<<endl;
    for(int i=0;i<n;i++) ord[cnt[s[i]]--] = i;

    int cc=0;  cls[ord[0]] = 0;
    for(int i=1;i < n; i++){

        if(s[ord[i]] == s[ord[i-1]]) cls[ord[i]] = cc;
        else                         cls[ord[i]] = ++cc;
    }

    while((1<<k) < n){
        countingSort();
        updateClass();
        k++;
    }

    /*for(int i=0;i<n;i++){
        cout<<ord[i]<<' ';
    }*/

    

    k=0;
	for(int i=0;i<n-1;i++){
		int j=ord[cls[i]-1];
		while(s[i+k]==s[j+k]) k++;
		lcp[i]=k;
		k=max(k-1,0);
	}


    long long i = 0, ans = n*(n-1)/2, val=0;
    stack<pair<int,long long int>> v;
    long long sum = 0;

    for(int i = 1;i < n;i++){
        int id = ord[i];   
        int val = lcp[id];

        int tot = 1;
        while(!v.empty() && v.top().first>val){
            sum -= (v.top().first-val) * v.top().second;
            tot += v.top().second;
            v.pop();
        }
        ans+=val+sum,sum+=val;
        if(!v.empty() && v.top().first == val) v.top().second+=tot;
        else                      v.push({val,tot});
    }
    cout<<ans<<endl;
}