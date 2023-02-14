#include<bits/stdc++.h>
using namespace std;
long long md = 998244353;
long long c[1000100],d[1000100];

long long pw(long long a,long long b){
    long long ret = 1;
    while(b){
        if(b&1) ret = (ret*a)%md;
        b/=2,a=(a*a)%md;
    }
    return ret;
}

int main(){
    int t;cin>>t;while(t--){
        long long int n,k=0,i,j;
        string a,b;
        cin>>n>>a>>b;
        for(i=0;i<n;i++) k+=(a[i]!=b[i]);


        c[n] = 1 , d[n] = 1;
        for(i=n-1;i>0;i--){
            long long de = ((n-(n-i)*d[i+1])%md+md)%md;
            de = pw(de,md-2);

            c[i] = (((n+(n-i)*c[i+1])%md)*de)%md;
            d[i] = (i*de)%md;
            //cout<<c[i]<<' '<<d[i]<<endl;
        }

        long long cons = c[k],mul = d[k];
        for(i=k-1;i>0;i--){
            cons = (cons+mul*(c[i]))%md;
            mul = (mul * d[i])%md;
        }

        cout<<cons<<endl;
    }
}