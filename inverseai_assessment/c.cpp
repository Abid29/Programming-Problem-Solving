#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long double vp,vd,t,f,c;
    cin>>vp>>vd>>t>>f>>c;

    long double disp = t*vp, disd = 0,tot=0, ans=0;

    if(vd<= vp ){
        cout<<0 <<endl;
        return 0;
    }

    while(disp<c){
        long double dis = (disp*vp)/ (vd-vp);
        
        //cout<<dis<<"  dis\n";
        
        disp =disp + dis;
        
        if(disp >= c) break;
        
        //cout<<disp<<' '<<dis<<endl;

        disp += f*vp + vp*(disp/vd);

        disd = 0;
        
        ans ++;

    }

    cout<<ans<<endl;
}