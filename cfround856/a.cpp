#include <bits/stdc++.h>
using namespace std;
string pal;
bool isPallindrome(string s){
    string r = s;
    reverse(r.begin(),r.end());
    return s==r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n,i,j;
        pal = "";
        string s[72];
        cin>>n;
        for(i=0;i<n+n-2;i++) cin>>s[i];
        if(n%2==0){
            string str = "";
            for(i=0;i<n+n-2;i++){
                if(s[i].size() == n/2) str += s[i];
            }
            if(isPallindrome(str)) cout<<"YES\n";
            else                   cout<<"NO\n";
        }
        else{
            string a;
            int  ind = 1;
            for(int ii=1;ii<n;ii++){
                for(i=0,j=0;i<n+n-2;i++){
                    if(s[i].size()==ii){
                        if(j==0) {a = s[i],j++;reverse(a.begin(),a.end());}
                        else{
                            ind = a==s[i];
                            if(ind==0) break;
                        }
                    }
                }
                if(ind==0) break;
            }

            if(ind == 0) cout<<"NO\n";
            else         cout<<"YES\n";
        }
    }
    return 0;
}