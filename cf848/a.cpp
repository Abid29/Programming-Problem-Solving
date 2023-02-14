#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    int t;cin>>t;
    while(t--){
        int  n,i;
        cin>>n;
        int tot = 0;
        for(i=0;i<n;i++){
            cin>>a[i];
            tot+=a[i];
        }
        int bal = 0;
        for(i=1;i<n;i++){
            if(a[i]==a[i-1]&&a[i]==-1){
                bal = 1;break;
            }
        }
        if(bal) cout<<tot+4<<endl;
        else if(tot<n) cout<<tot<<endl;
        else    cout<<tot-4<<endl;
    }
}