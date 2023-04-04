#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--){

        long long l = -1, r = 1e18+1;

        int q; cin >> q; while(q--){
            int ind; cin >> ind; 
            if(ind == 1){
                long long a,b,n,ll,rr;
                cin>>a>>b>>n;

                if(n == 1)    ll = 1, rr = a;
                else          ll = (n-2)*(a-b)+a+1, rr = (n-1)*(a-b)+a;

                if(ll>r || rr<l) cout << 0 <<' ';
                else{
                    cout<< 1 <<' ';
                    l = max(l,ll), r= min(r,rr);
                    //cout<<endl<<"l r "<<l<<' '<<r<<endl;
                }
            }
            else{
                long long a,b;
                cin>>a>>b;

                long long ll , rr , n;

                n = 1+max(l-a,0LL)/(a-b)+(max(l-a,0LL)%(a-b)>0);
                //cout<<endl<<n<<endl;

                if(n == 1)    ll = 1, rr = a;
                else          ll = (n-2)*(a-b)+a+1, rr = (n-1)*(a-b)+a;

                if(ll <= l && rr>= r) cout<<n<<' ';
                else                  cout<<-1<<' ';
            }
        }
        cout<<endl;
    }
}