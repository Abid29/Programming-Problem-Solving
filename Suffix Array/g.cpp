#include <bits/stdc++.h>
using namespace std;
long long phi(long long int n) {
    long long int result = n;
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long r,e;
    cin>>r>>e;
    if(__gcd(r,e)>1) cout<<phi(e);
    else       cout<<0;
    return 0;
}