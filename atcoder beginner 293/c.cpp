#include <bits/stdc++.h>
using namespace std;
int a[12][12],h,w;

int cnt(int i,int j,set<int>st){
    //cout<<i<<' '<<j<<endl;
    if(i==h && j==w) return 1;
    int ret1=0,ret2=0;
    if(i<h&&st.find(a[i+1][j])==st.end()){
        st.insert(a[i+1][j]);
        ret1 = cnt(i+1,j,st);
        st.erase(st.find(a[i+1][j]));
    }
    if(j<w&&st.find(a[i][j+1])==st.end()){
        st.insert(a[i][j+1]);
        ret2 = cnt(i,j+1,st);
    }
    return ret1+ret2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    cin>>h>>w;
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++) cin>>a[i][j];
    }
    set<int>st;
    st.insert(a[1][1]);
    int ans = cnt(1,1,st);
    cout<<ans;
}