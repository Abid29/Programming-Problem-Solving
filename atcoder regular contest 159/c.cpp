#include <bits/stdc++.h>
using namespace std;

void print(int x){
    int sum = 0;
    cout<<x<<"    ";
    while(x>0){
        sum += x%10;
        x/=10;
    }
    cout<<sum<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<1000;i++){
        print(i);
    }
}