#include<bits/stdc++.h>
using namespace std;
#define sz 160005 
int cnt[sz], ord[sz], cls[sz];
int k, nord[sz], ncls[sz];
int n;
long long int lcp[sz],l[sz],r[sz];

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
    int m,i,x;
    string s="";
    cin>>n>>m;
    long long int ans=n,id=1;
    for(i=0;i<n;i++){
        cin>>x;
        s += x-1+'a';
    }
    s+='$'; n++;
    //cout<<s<<endl;

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
        cout<<cls[i]<<' ';
    }*/
    

    k=0;
	for(int i=0;i<n-1;i++){
		int j=ord[cls[i]-1];
		while(s[i+k]==s[j+k]) k++;
		lcp[cls[i]]=k; //cout<<i<<lcp[i]<<endl;
		k=max(k-1,0);
	}
    //cout<<cls[0]<<lcp[0]<<endl;


    stack<pair<int,int>>st;
    st.push({lcp[1],1});
    for(i=2;i<n;i++){
        while(!st.empty() && st.top().first>lcp[i]){
            r[st.top().second] = i , st.pop();
        }
        st.push({lcp[i],i});
    }
    
    while(!st.empty()){
        r[st.top().second] = i , st.pop();
    }

    st.push({lcp[n-1],n-1});
    for(i=n-2;i>0;i--){
        while(!st.empty() && st.top().first>lcp[i]){
            l[st.top().second] = i , st.pop();
        }
        st.push({lcp[i],i});
    }
    while(!st.empty()){
        l[st.top().second] = i , st.pop();
    }


    //for(i=0;i<n-1;i++) cout<<lcp[i]<<' ';
    //cout<<endl;
    for(i=1;i<n;i++){
        if(ans < lcp[i] * (r[i]-l[i])){
            ans = lcp[i] * (r[i]-l[i]);
            id = i;
        }
    }
    if(!lcp[id]){
        cout<<ans<<endl<<ans<<endl;
        for(i=0;i<n-1;i++){
            int c = s[i]-'a'+1;
            cout<<c<<' ';
        }
        return 0;
    }
    cout<<ans<<endl<<lcp[id]<<endl;
    for(i=ord[id];lcp[id]--;i++){
        int c = s[i]-'a'+1;
        cout<<c<<' ';
    }
    
}