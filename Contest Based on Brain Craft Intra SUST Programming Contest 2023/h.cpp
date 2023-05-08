#include <bits/stdc++.h>
using namespace std;
long long tree[500005],s[100010],id,val,l,r,L,R;

void build(int ind,int st,int nd){
    if(st == nd){
        tree[ind] = (s[st] == 1); return;
    }
    int mid = (st+nd)/2;
    build(ind*2,st,mid),build(ind*2+1,mid+1,nd);
    tree[ind] = tree[ind*2]+tree[ind*2+1];
}

void update(int ind,int st,int nd){
    if(st > id || nd< id) return;
    if(st == nd){
        tree[ind] = val; return;
    }
    int mid = (st+nd)/2;
    update(ind*2,st,mid),update(ind*2+1,mid+1,nd);
    tree[ind] = tree[ind*2]+tree[ind*2+1];
}
long long int query(int ind,int st,int nd){
    if(st>r || nd < l) return 0;
    if(st>=l && nd<=r) return tree[ind];
    int mid = (st+nd)/2;
    return query(ind*2,st,mid)+query(ind*2+1,mid+1,nd);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q,i;
    cin>>n>>q;
    for(i=1;i<=n;i++) cin>>s[i];

    build(1,1,n);

    while(q--){
        int type;
        cin>>type>>l>>r; 
        if(type == 1){
            id = l,val = (r==1);
            update(1,1,n);
            s[id] = r;
        }
        else{
            if(s[l]>1){
                cout<<"First\n"; continue;
            }
            L=l,R=r;
            int ll = l,rr = r+1;
            while(ll+1<rr){
                int mid = (ll+rr)/2;

                //cout<<ll<<' '<<mid<<' '<<query(1,1,n)<<endl;
                l = ll, r = mid;
                if(query(1,1,n) == mid-ll+1) ll = mid;
                else                            rr = mid;

            }
            //cout<<ll<<endl;
            if(ll == R){
                if((R-L+1)&1) cout<<"First\n";
                else          cout<<"Second\n";
                continue;
            }
            if((ll-L+1)&1)      cout<<"Second\n";
            else                cout<<"First\n";
        }
    }
}