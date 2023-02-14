#include<bits/stdc++.h>
using namespace std;
int p[200100],q[200010],pl[200100],pr[2000100];
int ql[200010],qr[200010];
int main(){
    int t;cin>>t;while(t--){
        int n,i;
        cin>>n;
        set<int>st;
        for(i=1;i<=n+1;i++) pl[i] = ql[i] = n+3;
        for(i=1;i<=n;i++){
            cin>>p[i];
            st.insert(i);
        }
        st.insert(n+1);
        int mex = 0;
        for(i=1;i<=n;i++){
            st.erase(st.find(p[i]));
            mex=*st.begin();
            pl[mex] = min(pl[mex],i);
            pr[mex] = max(pr[mex],i);
        }

        for(i=1;i<=n;i++){
            cin>>q[i];
            st.insert(i);
        }
        st.insert(n+1);
        
        mex = 0;
        for(i=1;i<=n;i++){
            st.erase(st.find(q[i]));
            mex=*st.begin();
            ql[mex] = min(ql[mex],i);
            qr[mex] = max(qr[mex],i);
        }

        long long ans = 0;

        for(mex=1;mex<=n+1;mex++){
            //cout<<mex<<' '<<pl[mex]<<' '<<pr[mex]<<endl;
            if(pl[mex]==n+3||ql[mex]==n+3) continue;
            if(pl[mex] < ql[mex]){
                ans += (ql[mex]-pl[mex]) * (qr[mex] - ql[mex]);
            }
            if(pr[mex]>=ql[mex]){
                long long val = min(qr[mex],pr[mex]) - ql[mex]+1;
                ans += val*(val+1)/2;
                if(pr[mex]<qr[mex]){
                    ans+=val*(qr[mex] - pr[mex]);
                }

            }
        }
        cout<<ans<<endl;
    }
}