#include<bits/stdc++.h>
using namespace std;
#define sz 400050 
int cnt[sz], ord[sz], cls[sz];
int k, nord[sz], ncls[sz] , n;
int lcp[sz] , ans;

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

//Hacked by ESHA

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

    //counter test case "abcdbzabcdabcdk"

    k=0;
	for(int i=0;i<n-1;i++){
		int j=ord[cls[i]-1];
		while(s[i+k]==s[j+k]) k++;
		//lcp[i]=k;
        int dif = abs(i-j);
        ans = max(ans , k/dif ) ;

		k=max(k-1,0);
	}

    cout<<ans + 1<<endl;
}