#include <bits/stdc++.h>
using namespace std;
int c[100100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i,mx = 0;
    cin>>n;
    for(i=0;i<n;i++){
        int x; cin>> x;
        c[x]++;
        mx = max(mx,c[x]);
    }

    cout<<max((n+1)/2,mx);
}