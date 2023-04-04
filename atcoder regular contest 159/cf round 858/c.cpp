#include <bits/stdc++.h>
using namespace std;
int aa[4]={-2,-2,2,2};

int f(vector<int>v){
    int tot = 0,ret=1000;
    for(int i=0;i<4;i++) tot += v[i];
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            int sum = tot-v[i]-v[j];
            if(v[i]*v[j]!= sum) continue;
            int can = 0;
            for(int k=0;k<4;k++){
                can += abs(aa[k]-v[k]);
            }
            ret = min(ret,can);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[10];
    for(int i=0,j=-4;i<9;i++,j++){
        a[i] = j;
    }



    vector<int>v;
    int ans = 20000;
    for(int i=0;i<9;i++){
        v.push_back(a[i]);
        for(int j=0;j<9;j++){
            if(i==j) continue;
            v.push_back(a[i]);
            for(int k=0;k<9;k++){
                if(i==k||j==k) continue;
                v.push_back(a[i]);
                for(int l=0;l<9;l++){
                    if(i==l||j==l||k==l) continue;
                    v.push_back(a[i]);
                    ans = min(ans,f(v));
                }
            }
            v.pop_back();
        }
        v.pop_back();
    }
    cout<<ans<<endl;
}