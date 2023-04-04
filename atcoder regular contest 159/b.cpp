#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>pos,neg;
    int n,i,x;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        if(x>0) pos.push_back(x);
        else    neg.push_back(x);
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    vector<int>modi_x;
    if(pos.size()>6){
        for(i=0;i<3;i++){
            modi_x.push_back(pos[i]);
        }
        i=3; while(i--){
            modi_x.push_back(pos.back());
            pos.pop_back();
        }
    }
    else{
        for(int it : pos) modi_x.push_back(it);
    }

    if(neg.size()>6){
        for(i=0;i<3;i++){
            modi_x.push_back(neg[i]);
        }
        i=3; while(i--){
            modi_x.push_back(neg.back());
            neg.pop_back();
        }
    }
    else{
        for(int it : neg) modi_x.push_back(it);
    }

    n = modi_x.size();

    long double mx = -10000000,mn=10000000;
    for(int mask=7;mask<(1<<n);mask++){
        int bit_cnt=0;
        for(i=0;i<n;i++) bit_cnt += (mask&(1<<i))>0;

        if(bit_cnt!=3) continue;

        long double a[3];
        int j = 0;
        for(i=0;i<n;i++){
            if(mask & (1<<i)){
                a[j++] = modi_x[i];
            }
        }

        long double can = (a[0]+a[1]+a[2])/(a[0]*a[1]*a[2]);

        mx = max(mx,can);
        mn = min(mn,can);
    }
    cout<<fixed<<setprecision(15);
    cout<<mn<<'\n'<<mx;
}