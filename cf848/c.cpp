#include<bits/stdc++.h>
using namespace std;
int val[300];
int main(){
    int t; cin>>t;while(t--){
        int n,k,i,j;
        string a,b;
        cin>>n>>k>>a>>b;
        map<int,int>mp;
        int cnt = 0;
        for(char ch : a){
            if(mp[ch]==0){
                val[ch] = cnt++;
                mp[ch] = 1;
            }
        }
        long long ans = 0;
        for(int mask = 0;mask<(1<<10);mask++){
            //cout<<mask<<endl;
            int bitcnt = 0;
            for(int bit = 0;bit<10;bit++){
                bitcnt += ((mask>>bit)&1);
            }
            //cout<<bitcnt<<endl;
            if(bitcnt!=k) continue;
            long long can = 0;
            long long balsal=0;
            for(i=0;i<n;i++){
                
                if(a[i]==b[i] || (mask&(1<<val[a[i]]))){
                    balsal++;
                }
                else{
                    can+=balsal*(balsal+1)/2;
                    balsal = 0;
                }
            }
            can+=balsal*(balsal+1)/2;
            //cout<<mask<<' '<<can<<endl;
            ans=max(ans,can);
        }
        cout<<ans<<endl;
    }
}