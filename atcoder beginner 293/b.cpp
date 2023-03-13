#include <bits/stdc++.h>
using namespace std;
int a[200100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,n,x;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        if(a[i]==0) a[x] = 1;
    }
    int sum = 0;
    for(i=1;i<=n;i++){
        sum += (a[i]==0);
    }
    cout<<sum<<'\n';
    for(i=1;i<=n;i++){
        if(a[i]==0) cout<<i<<' ';
    }
}