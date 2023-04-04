#include <bits/stdc++.h>
using namespace std;

int dp[10010][105],x,m;

int cal(int val, int moves){
    if(moves == 0) return x < val;

    if(dp[val][moves] != -1) return dp[val][moves];

    int val1 = val;
    if((moves&1) == (m&1)){
        dp[val][moves] = 0;
        for(int mul = 1; mul < 1001;mul *= 10){
            int digit = val1%10;
            val1 /= 10;
            if(digit == 9){
                dp[val][moves] |= cal(val - 9*mul,moves-1);
            }
            else{
                dp[val][moves] |= cal(val + mul,moves-1);
            }
        }
    }
    else{
        dp[val][moves] = 1;
        for(int mul = 1; mul < 1001;mul *= 10){
            int digit = val1%10;
            val1 /= 10;
            if(digit == 9){
                dp[val][moves] &= cal(val - 9*mul,moves-1);
            }
            else{
                dp[val][moves] &= cal(val + mul,moves-1);
            }
        }
    }
    return dp[val][moves];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--){

        cin>>x>>m;

        memset(dp,-1,sizeof(dp));
        
        if(cal(x,m)) cout<<"Ada\n";
        else         cout<<"Vinit\n";

    }
}