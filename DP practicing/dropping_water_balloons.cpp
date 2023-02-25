#include <bits/stdc++.h>
using namespace std;
long long dp[110][70]; //dp[balloon][trial]=buildingHeight
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long int k,n,i,j;
    cin>>k>>n;
    while(k){
        for(i=0;i<=63;i++){
            dp[i][0]=dp[0][i] = 0;
            dp[i][1] = 1;
        }

        for(i=1;i<=63;i++){
            for(j=1;j<=63;j++){
                dp[i][j] = 1+dp[i-1][j-1]+dp[i][j-1];
            }
        }

        k=min(k,(long long)63);

        for(i=1;i<=63;i++){
            if(dp[k][i]>=n) break;
        }
        if(i==64) cout<<"More than 63 trials needed.\n";
        else      cout<<i<<'\n';
        cin>>k>>n;
    }
}