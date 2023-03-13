#include <bits/stdc++.h>
using namespace std;

int d;

void matrix_mul(vector<vector<unsigned>>&a,vector<vector<unsigned>>&b){
    vector<vector<unsigned>> ret(d,vector<unsigned>(d,0));
    int row,col,k;
    for(row = 0; row < d; row++){
        for(col = 0;col < d; col++){
            for(k=0;k<d;k++){
                ret[row][col] += a[row][k]*b[k][col];
            }
        }
    }
    a = ret;
}

vector<vector<unsigned>>matrix_ex(vector<vector<unsigned>>&a,long long int n){
    vector<vector<unsigned>>ret(d,vector<unsigned>(d,0));
    for(int i = 0;i < d;i++) ret[i][i] = 1;

    while(n>0){
        if(n&1) matrix_mul(ret,a);
        n/=2 ,  matrix_mul(a,a);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t,tc=1; cin>>t; while(t--){
        int base,score;
        cin>>base>>score;
        int lim = (base-1)*(base-1);

        vector<vector<unsigned>>dp(120,vector<unsigned>(base,0));
        for(int i=1;i<base;i++) dp[0][i] = 1;

        for(int i=1;i<=100;i++){
            for(int j=0;j<base;j++){
                for(int dif=1;dif<base;dif++){
                    int jj = j-dif,val=dif*dif;
                    if(i<val) break;
                    if(jj>=0 && jj<base){
                        dp[i][j] += dp[i-val][jj]; 
                    }
                    jj=j+dif;
                    if(jj>=0 && jj<base){
                        dp[i][j] += dp[i-val][jj]; 
                    }
                }
            }
        }

        int val = (base-1)*(base-1);
        if(score<=val){
            unsigned ans = 0;
            for(int i=0;i<base;i++) ans += dp[score][i];
            cout<<"Case "<<tc++<<": "<<ans<<'\n';
            continue;
        }
        score -= val-1;
        d=val*base;
        vector<vector<unsigned>>a(val*base,vector<unsigned>(val*base,0));
        for(int j=0,id=(val-1)*base;j<base;j++,id++){
            for(int dif=1;dif<base;dif++){
                int jj = j-dif,vall=dif*dif;
                if(i<vall) break;
                if(jj>=0 && jj<base){
                    a[id][(i-vall)*base+jj] = 1;
                }
                jj=j+dif;
                if(jj>=0 && jj<base){
                    a[id][(i-vall)*base+jj] = 1; 
                }
            }
        }
        
        for(vector<unsigned>it : a){
            for(unsigned itt : it){
                cout<<itt<<' ';
            }
            cout<<endl;
        }
        
        /*
        vector<vector<unsigned>>a_n = matrix_ex(a,score);
        unsigned ans = 0;
        for(int i=(val-1)*base;i<val*base;i++){
            for(int j=0;j<val*base;j++){
                ans += a_n[i][j]*dp[val][j%val];
            }
        }
        unsigned ans1 = 0;
        for(int i=0;i<base;i++) ans1 += dp[score][i];
        cout<<ans;
        cout<<"abid";
        cout<<endl<<ans1<<endl;*/
    }
}