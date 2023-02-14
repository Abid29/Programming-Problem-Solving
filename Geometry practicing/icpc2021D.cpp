#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt=1,t;cin>>t;while(t--){
        long double s,r,m;
        cin>>s>>m>>r;
        long double area = (long double)200.0*acos(-1.0)*100.00*(1.0-100.00/abs(s));
        if(s*m>=0&&abs(s)>abs(m)){
            long double dis = abs(s)-abs(m);
            if(r/dis>=100.00/abs(s)) area = 0;
            else{
                long double alpha = asin(r/dis);
                long double beta = asin(s*r/(dis*100));
                long double theta = acos(-1)-alpha-beta;
                area -= (long double)200.0*acos(-1.0)*100.00*(1.0-cos((acos(-1)/2)-theta));
            }
        }
        cout<<fixed<<setprecision(8);
        long double tot = (long double)4.00*acos(-1.0)*10000.00;
        cout<<"Case "<<tt++<<": "<<(area/tot)<<'\n';
    }
}