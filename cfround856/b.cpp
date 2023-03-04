#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,i;
        cin>>n;
        for(i=0;i<n;i++) cin>>a[i];
        a[0]++;
        for(i=1;i<n;i++){
            if(a[i]%a[i-1]==0) a[i]++;
        }
        for(i=0;i<n;i++) cout<<a[i]<<' ';
        cout<<endl;
    }
}