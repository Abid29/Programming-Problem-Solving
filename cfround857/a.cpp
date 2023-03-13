#include <bits/stdc++.h>
using namespace std;
int b[200];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,i;
        cin>>n;
        int pos=0;
        for(i=0;i<n;i++){
            cin>>b[i];
            if(b[i]>0) pos++;
        }
        int tot = 1;
        while(tot<=pos){
            cout<<tot<<' ';tot++;
        }
        --tot;
        int val = n-pos;
        while(val--){
            --tot;
            cout<<tot<<' ';
        }
        cout<<'\n';
        int m = n-pos;
        while(m--){
            cout<<"1 0 ";
        }
        pos-=n-pos;
        val=1;
        while(pos>0){
            cout<<val<<' ';
            val++,pos--;
        }
        cout<<endl;


    }
}