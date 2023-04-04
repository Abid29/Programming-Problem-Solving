#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long a,b;
    cin>>a>>b;
    unsigned long long x,y;
    x = (a-b)/2;
    y = a - x;

    if((x^y) == b){
        cout<<x<<' '<<y;
    }
    else cout<<-1;
}