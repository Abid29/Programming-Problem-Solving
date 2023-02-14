#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;while(t--){
        int n,x,i; cin>>n;
        vector<int>odd,even;
        for(i=0;i<n;i++){
            cin>>x;
            if(x&1) odd.push_back(i+1);
            else    even.push_back(i+1);
        }
        if(odd.size()==0) puts("NO");
        else{
            if(odd.size()>=3){
                puts("YES");
                cout<<odd[0]<<' '<<odd[1]<<' '<<odd[2]<<endl;
            }
            else if(even.size()>=2){
                puts("YES");
                cout<<odd[0]<<' '<<even[0]<<' '<<even[1]<<endl;
            }
            else{
                puts("NO");
            }
        }
    }
}