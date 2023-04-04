#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    long long sum = 0;
    for(int i=0;i<3;i++) sum+=a[i];
    if(sum%3){
        cout<<-1<<endl; return;
    }
    sum /= 3;
    for(int i=1;i<3;i++){
        if((abs(a[i]-sum)%2)!=(abs(a[0]-sum)%2)){
            cout<<-1<<endl; return;
        }
    }
    long long tot=0;
    for(int i=0;i<3;i++) tot += abs(a[i]-sum);

    if(tot%4!=0){
        cout<<-1<<endl; return;
    }
    cout<<tot/4<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}