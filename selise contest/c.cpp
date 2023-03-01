#include <bits/stdc++.h>
using namespace std;
int dp[65][65][10][8];

int f(int l,int r,int cnt,int nocnt){
    if(cnt>7 || nocnt>3) return -1;
    if(r < l)  return 1;
    if(l > r)  return 1;
    if(dp[l][r][cnt][nocnt]!=0) return dp[l][r][cnt][nocnt];
    for(int i = l;i <= r;i++){
        int a = f(i+1,r,cnt+1,nocnt);
        int b = f(l,i-1,cnt+1,nocnt+1);
        if(a != -1 && b != -1){
            dp[l][r][cnt][nocnt] = i;
            return i;
        }
    }
    dp[l][r][cnt][nocnt] = -1;
    return -1;
}

string query(long long int x){
    cout<<"? "<<x<<'\n';
    cout.flush();
    string ret; cin>>ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f(0,59,0,0);
    int l = 0,r = 60,cnt = 0,nocnt = 0;
    while(l<r){
        //if(dp[l][r-1][cnt][nocnt] == -1) cout<<"abid\n";
        string st = query((long long)1<<dp[l][r-1][cnt][nocnt]);
        if(st == "yes"){
            l = dp[l][r-1][cnt][nocnt]+1;
            cnt++;
        }
        else{
            r = dp[l][r-1][cnt][nocnt];
            cnt++ , nocnt++;
            
        }
        //cout<<l<<' '<<r<<' '<<dp[l][r-1][cnt][nocnt]<<endl;
    }
    if(l==r) l--;
    cout<<"! "<<((long long)1<<l)<<'\n';
    cout.flush();
}