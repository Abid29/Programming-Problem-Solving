#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    long long int n,c,i;
    cin>>n>>c>>s;
    long long rudeness=0,a=0,b=0,l=0,r=1,ans=1;
    a = s[0]=='a';
    b = s[0]=='b';
    while(r<n){
        if(s[r] == 'a'){
            a++;
        }
        else if(s[r] == 'b'){
            b++;
            rudeness += a;
        }
        while(rudeness>c){
            if(s[l] == 'a'){
                rudeness -= b;
                a--;
            }
            else if(s[l] == 'b') b--;
            l++;
        }
        ans = max(ans,r-l+1); r++;
    }
    cout<<ans;
}