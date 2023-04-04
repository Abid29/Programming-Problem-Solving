#include <bits/stdc++.h>
using namespace std;
int v[20];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;while(t--){
        long long int l,r;
        cin>>l>>r;

        if(l<10){
            cout<<l<<endl;
            continue;
        }
        
        r = min(r,l+10);
        int ans = 10;
        long long val;
        for(long long i =l;i<=r;i++){
            if(ans == 0) break;
            for(int j=0;j<10;j++){
                v[j] = 0;
            }
            long long c = i;

            while(c>0){
                v[(c%10)]++;
                c/=10;
            }

            for(int j=0;j<10;j++){
                if(v[j]>1){
                    ans = 0;
                    val = i;
                    break;
                }
            }

            for(int j=0;j<10;j++){
                for(int k=j+1;k<10;k++){
                    if(v[j]==1&&v[k]==1){
                        if(ans > k-j){
                            ans = k-j;
                            val = i;
                        }

                    }
                }
            }
        }
        cout<<val<<endl;
    }
}