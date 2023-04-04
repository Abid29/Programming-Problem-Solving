#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--){
        string s;
        cin >> s;
        long long int zero = 0;
        for(char ch : s) zero += ch=='0';

        long long a = 1000000000000;
        long long b = a+1;
        long long ans = zero * b;

        int id = -1;

        long long can = 0,now=0,last = 0 , one=0;

        for(char ch : s){
            if(ch == '0'){
                zero--;
                can = one*b + now*a+ zero*b;
                one+=now, now = 0;

                //cout<<can<<endl;

                ans = min(ans,can);
            }
            else{
                now++;
            }
        }

        cout<< ans <<endl;

    }
}