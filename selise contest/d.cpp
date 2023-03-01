#include <bits/stdc++.h>
using namespace std;
string s ;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(getline(cin,s)){
        long long tot = 0,ans = 0;
        int n=s.size();
        int i=n/2-1,j=n/2+(n%2);
        while(i>=0){
            tot%=26;
            int val = s[j]-'a';
            val+=tot;
            val%=26;
            int dif = abs(s[i]-'a'-val);
            if(s[i]-'a'>=val){
                tot+=dif;
                ans+=dif;
            }
            else{
                tot+=26-dif;
                ans+=26-dif;
            }
            i--,j++;
        }
        cout<<ans<<endl;
    }
    return 0;
}