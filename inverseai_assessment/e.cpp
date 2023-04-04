#include <bits/stdc++.h>
using namespace std;
const int mx = 1005; int n,m,k;
int gd[mx][mx],dp[mx][mx][2],turn[(mx*mx)][2];

pair<int,int> check(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j][0] = dp[i][j][1] = 0;
            if(gd[i][j] == 1){
                dp[i][j][0] = dp[i][j-1][0]+1;
            }
            else if(gd[i][j] ==2){
                dp[i][j][1] = dp[i][j-1][1]+1;
            }
        }
    }

    pair<int,int>ret = {0,0};

    for(int j=k;j<=m;j++){
        int cnt1 = 0,cnt2=0;
        for(int i=1;i<=n;i++){
            if(dp[i][j][0] >= k) cnt1++;
            else                 cnt1=0;

            if(dp[i][j][1] >= k) cnt2++;
            else                 cnt2=0;

            ret.first |= cnt1 >= k;
            ret.second |= cnt2 >= k;
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--){
        cin >> n >> m >> k;

        for(int i = 1, tot = n*m; i <= tot; i++){
            cin>> turn[i][0] >> turn[i][1];
        }

        int lo = k*k-1 , hi = n*m+1, still = 1;

        while(lo+1 < hi){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    gd[i][j] = 0;
                }
            }

            int mid = (lo+hi)/2;

            for(int i=1;i<=mid;i++){
                gd[turn[i][0]][turn[i][1]] = (i&1)?1:2;
            }

            pair<int,int> pa = check();

            if(pa == make_pair(1,1)){
                hi = mid;
            }
            else if(pa == make_pair(0,0)){
                lo = mid;
            }
            else{
                if(pa.first == 1)  cout<<"Alice\n";
                else               cout<<"Bob\n";
                still = 0;
                break;
            }
        }
        if(still) cout<<"Draw\n";
    }
    
}