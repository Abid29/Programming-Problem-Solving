#include<bits/stdc++.h>
using namespace std;
long long val[211], x,y;


void extended_gcd(long long a, long long b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    extended_gcd(b, a % b);
    long long ind = x;
    x = y;
    y = ind - y * (a / b);
}

int main(){
    int t; cin>>t; t += t;
    for(int i = 1;i <= t;i+=2){
        cin>>val[i];
    }
    long long a;
    for(a = 0;a <10001;a++){
        long long int p = a+1,q = 10001,r = val[3] - a * a * val[1];
        long long k = __gcd(p,q);
        long long c = val[3] - a*a*val[1];
        if(c%k) continue;
        k=c/k;
        
        extended_gcd(p,q);
        x*=k; x%=10001;
        
        int i;
        for(i = 3;i<=t;i+=2){
            if(val[i] != ((a*((a*val[i-2]+x+10001))%10001)+x+10001)%10001) break;
        }
        if(i==t+1) break;
    }
    
    for(int i=2;i<=t;i+=2){
        cout<<(a*val[i-1]+x+10001)%10001<<endl;
    }
    
}