#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[555];
int cnt1[555];
int cnt2[555];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t=1;cin>>n;
    getline(cin,s);
    string bal = "SELISE Digital Platforms";
    for(char ch : bal) cnt2[ch]++;
    bal = "SELISE";
    for(char ch : bal) cnt1[ch]++;

    while(n--){
        getline(cin,s);
        for(int i=0;i<300;i++) cnt[i] = 0;
        for(char ch : s) cnt[ch]++;
        bool ind1=1,ind2=1;
        for(int i=0;i<300;i++) if(cnt[i]<cnt1[i]) ind1=0;
        for(int i=0;i<300;i++) if(cnt[i]<cnt2[i]) ind2=0;
        if(ind1&&ind2){
            cout<<"Case "<<t++<<": BOTH\n";
        }
        else if(ind1){
            cout<<"Case "<<t++<<": SELISE\n";
        }
        else if(ind2){
            cout<<"Case "<<t++<<": SELISE Digital Platforms\n";
        }
        else{
            cout<<"Case "<<t++<<": NONE\n";
        }
    }
    return 0;
}