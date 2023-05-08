#include <bits/stdc++.h>
using namespace std;

vector<int>divisor[500100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<=500000;i++){
        for(int j=i;j<=500000;j+=i){
            divisor[j].push_back(i);
        }
    }

    int t; cin>>t;while(t--){
        long long a,b,m1,m2;
        cin>>a>>b>>m1>>m2;

        long long x;

        if(m1>a || m2 > b){
            cout<<"-1\n";
            continue;
        }

        if(m1 == a){
            if(m2 == b){
                cout<<max(a,b)+1<<'\n'; 
                continue;
            }
            else{
                if(b-m2>a){
                    long long val = b-m2;
                    int cur = 1e9;

                    for(int i : divisor[val]){
                        if(i > a && i > m2){
                            cur = min(cur , i);
                        }
                    }
                    if(cur == 1e9){
                        cout<<"-1\n"; continue;
                    }
                    else{
                        cout<<cur<<'\n'; continue;
                    }

                }
                else{
                    cout<<"-1\n";
                }
            }
        }
        if(m2 == b){
            if(m1 == a){
                cout<<max(a,b)+1<<'\n'; 
                continue;
            }
            if(a-m1 > b){
                long long val = a-m1;
                int cur = 1e9;

                for(int i : divisor[val]){
                    if(i > b && i > m1){
                        cur = min(cur , i);
                    }
                }
                if(cur == 1e9){
                    cout<<"-1\n"; continue;
                }
                else{
                    cout<<cur<<'\n'; continue;
                }
            }
            else{
                cout<<"-1\n";
                continue;
            }
        }
        int val1 = a-m1,val2=b-m2,cur = 1e9;


        for(int i : divisor[val1]){
            if(val2 % i ==0){
                if(i>m1 && i>m2){
                    cur = min(cur,i);
                }
            }
        }
        if(cur == 1e9) cout<<"-1\n";
        else           cout<<cur<<'\n';
    }
}