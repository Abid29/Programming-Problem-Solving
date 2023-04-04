#include <bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        long long int n,c,d;
        cin>>n>>c>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        sort(a+1,a+n+1);
        long long ans ,i=1,sum = 0;
        if(a[1] != 1){
            a[0] = 1;
            sum = d;
            ans = d+n*c;
        }
        else i = 2,ans = (n-1)*c,a[0]=0;

        for(;i<=n;i++){
            if(a[i] == a[i-1]){
                sum += c; 
            }
            else  sum += (a[i] - a[i-1]-1)*d;
            //cout<<i<<' '<<sum<<endl;
            ans = min(ans,sum+(n-i)*c);
        }
        cout<<ans<<endl;
    }
}