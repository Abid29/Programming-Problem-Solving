#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>> t; while(t--){
        int n,i;
        cin>>n;
        int mex=0;
        for(i=0;i<n;i++){
            cin>>a[i];
            b[i] = a[i];
        }
        sort(b,b+n);
        if(b[0]==0)for(i=0;i<n;i++){
            if(mex == b[i]) mex++;
        }
        //cout<<mex<<endl;

        if(mex == n){
            puts("no"); continue;
        }

        int l=n,r;
        for(i=0;i<n;i++) if(a[i] == mex+1){
            l=i;break;
        }

        if(l>=n){
            puts("Yes");
            continue;
        }
        r=l;
        for(;i<n;i++) if(a[i] == mex+1) r = i;

        int j=0;
        for(i=0;i<l;i++) b[j++] = a[i];
        for(i=r+1;i<n;i++) b[j++] = a[i];
        sort(b,b+j);
        int mm = 0;
        if(b[0]==0)for(i=0;i<j;i++){
            if(mm == b[i]) mm++;
        }

        //cout<<mex<<mm<<endl;

        if(mm== mex) puts("Yes");
        else puts("No");
    }

}