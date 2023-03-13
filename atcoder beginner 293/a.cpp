#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int i,n=s.size();
    for(i=0;i<n;i+=2){
        cout<<s[i+1]<<s[i];
    }
}