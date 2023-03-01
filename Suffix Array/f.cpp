#include <bits/stdc++.h>
using namespace std;
int n;
string s[5100];
bool p[5100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string ss;
    int x;
    for(int i=1;i<=n;i++){
        cin>>ss>>x;
        s[x] = ss;
        p[x] = 1;
    }

    cout<<"Selise Coding Challenge 2023 Winners\n";
    int i;
    for(i=1;i<=5000;i++){
        if(p[i]){
            cout<<"Winner: ";
            cout<<s[i]<<" => "<<i<<'\n';
            i++;break;
        }
    }
    for(;i<=5000;i++){
        if(p[i]){
            cout<<"1st Runner Up: ";
            cout<<s[i]<<" => "<<i<<'\n';
            i++;break;
        }
    }
    for(;i<=5000;i++){
        if(p[i]){
            cout<<"2nd Runner Up: ";
            cout<<s[i]<<" => "<<i<<'\n';
            i++;break;
        }
    }

    return 0;
}