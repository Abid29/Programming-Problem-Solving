#include <bits/stdc++.h>
using namespace std;
long long a[200100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; 
    cin>>n>>k;
    
    for(int i=0;i<n;i++) cin>>a[i];

    if(k==1){
        cout<<n<<endl;
        return 0;
    }

    int l = -1,r=n-1;
    while(l+1<r){
        int mid = (l+r)/2,cnt=0;
        for(int i=mid;i<n;i++){
            if(a[mid]%a[i]==0) cnt++;
        }
        if(cnt>=k){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    if(l!=-1) l++;
    cout<<l;
}