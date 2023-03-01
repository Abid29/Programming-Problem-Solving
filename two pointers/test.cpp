#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[10+1];
    for(int i = 1; i <= 10; i++) a[i] = i;
    int prefix[11];
    prefix[1] = a[1];
    for(int i = 2; i <= 10; i++){
        prefix[i] = prefix[i-1] + a[i];
    }
    return 0;
}