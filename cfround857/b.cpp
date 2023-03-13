#include <bits/stdc++.h>
using namespace std;
int b[200];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,i,d;
        cin>>n;
        int last = 0,sum = 0;
        int ans = 0;
        for(i=1;i<=n;i++){
            cin>>d;
            if(d==2){
                if(last==i-1){
                    last=i;continue;
                }
                int pig = i-last-1;
                ans = max(ans,(sum)/2+(sum!=0)+pig);
                sum += pig;
                last = i;
            }
        }
        ans = max(ans,(sum)/2+(sum!=0)+i-last-1);
        cout<<ans<<'\n';
    }
}