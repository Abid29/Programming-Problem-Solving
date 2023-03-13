#include <bits/stdc++.h>
using namespace std;
long long mx = (1e18);

long long ex(long long a,long long b){
    long long int ret = 1;
    while(b>0){
        if(b&1){
            if((long long)(mx/a)<ret) return mx;
            ret = ret*a;
        }
        b/=2; if(b==0) return ret;
        if((long long)(mx/a)<a){
        	return mx;
        }
        a=a*a;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mx+=1;
    int t;cin>>t;while(t--){
        long long n;
        cin>>n;
        int ans = 2-(n==2);
        for(long long i=3;i<65;i++){
            long long l=2,r=mx;
            while(l+1<r){
                long long mid = (l+r)/2;
                long long val = ex(mid,i-1);
                if(val > n){
                    r=mid;
                }
                else{
                    l=mid;
                }
            }
            int cnt = 0;
            long long m=n;
            while(m>0){
                if(m%l>1) break;
                m/=l,cnt++;
            }
            if(m==0&&cnt==i) ans++;
        }
        cout<<ans<<endl;
    }
}