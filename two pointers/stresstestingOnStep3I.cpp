#include<bits/stdc++.h>
using namespace std;
long long a[100005],dp[10005],s,n=20;
int amarBalerfunction(){
    dp[0] = 1;
    int l=1,r=2,ans=1e6,i;
    for(i=1;i<2020;i++) dp[i]=0;
    dp[a[l]] = 1;

    if(dp[s] == 1){
        cout<<1;return 0;
    }


    while(r<=n){
        for(i=s;i>=a[r];i--){
            dp[i] += (dp[i-a[r]]);
        }
        r++;
        while(dp[s]>0){
            //cout<<r<<" "<<l<<" "<<dp[s]<<endl;
            ans = min(ans,r-l);
            for(i=0;i<s;i++){
                if(dp[i]) dp[i+a[l]] -= dp[i];
            }
            l++;
        }

    }
    if(ans==1e6) ans = -1;
    return ans;
}

int bruteforce(){
    int l=1,r=1,ans = 1e6;
    for(l=1;l<=n;l++){
        for(r=l;r<=n;r++){
            int tot = r-l+1;
            if(tot>=ans) continue;
            for(int mask = 0;mask<(1<<tot);mask++){
                int sum = 0;
                for(int i = 0;i<tot;i++){
                    if(mask&(1<<i)){
                        sum += a[l+i];
                    }
                }
                if(sum == s){
                    ans = min(ans,r-l+1); break;
                }
            }
        }
    }
    if(ans == 1e6) ans = -1;
    return ans;
}

int main(){
    long long int i,t=50;
    while(t--){
        s=5*rand()%100; s++;
        for(i=1;i<=n;i++){
            a[i] = (i*rand())%100;
            a[i]++;
        }
        if(amarBalerfunction()!=bruteforce()){
            puts("NO");
            for(i=1;i<=n;i++) cout<<a[i]<<' ';
            break;
        }
        puts("YES");
    }
    
}