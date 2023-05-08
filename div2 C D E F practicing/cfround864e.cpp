#include <bits/stdc++.h>
using namespace std;
int par[5000100],a[100100],l,r;
pair<int,int>seg[400000];
set<int>st;

pair<int,int> comanc(pair<int,int> x,pair<int,int> y,int sz1,int sz2){
    if(x.first == -1) return y;
    if(y.first == -1) return x;
    if(x.first == y.first) return make_pair(x.first,(x.second+y.second));
    if(x.first > y.first) return comanc(make_pair(par[x.first],x.second+sz1),y,sz1,sz2);
    return comanc(x,make_pair(par[y.first],y.second+sz2),sz1,sz2);
}

void build(int ind,int st,int nd){
    if(st == nd){
        seg[ind] = {a[st],0};
        return;
    }
    int mid = (st+nd)/2;
    build(ind*2,st,mid),build(ind*2+1,mid+1,nd);
    seg[ind] = comanc(seg[ind*2],seg[ind*2+1],mid-st+1,nd-mid);
}

void update(int ind,int st,int nd,int pos){
    if(st > pos || nd < pos){
        return;
    }
    if(st == nd){
        seg[ind] = {a[st],0};
        return;
    }
    int mid = (st+nd)/2;
    update(ind*2,st,mid,pos),update(ind*2+1,mid+1,nd,pos);
    seg[ind] = comanc(seg[ind*2],seg[ind*2+1],mid-st+1,nd-mid);
}

pair<int,int> query(int ind,int st,int nd){
    if(st > r || nd < l){
        return make_pair(-1,0);
    }
    if(st >= l && nd <= r){
        return seg[ind];
    }
    int mid = (st+nd)/2,sz1,sz2;
    if(r<=mid){
        sz2 = 0,sz1 = r-max(l,st)+1;
    }
    else if(l>mid){
        sz1 = 0,sz2 = min(nd,r)-l+1;
    }
    else{
        sz1 = mid - max(l,st)+1;
        sz2 = min(r,nd) - mid;
    }

    return comanc(query(ind*2,st,mid),query(ind*2+1,mid+1,nd),sz1,sz2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0;i <= 5000000;i++) par[i] = i;
    for(int i = 2;i <= 5000000;i++){
        if(par[i] != i) continue;
        for(int j = i,cnt=1;j <= 5000000;j += i){
            par[j] -= par[j]/i;
        }
    }

    //for(int i = 1;i < 9;i++) cout<<par[i]<<' ';
    //cout<<endl;
    int n,m;
    cin>> n >> m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i] > 1) st.insert(i);
    }

    build(1,1,n);
    //cout<<seg[3].first<<' '<<seg[3].second<<endl; 
    //cout<<par[6]<<par[7]<<par[8]<<endl;
    //cout<<comanc({6,0},{3,0},1,1).first<<endl;

    while(m--){
        int t; cin>> t>> l>> r; 
        if(t == 1){
            for(auto it = st.lower_bound(l);it!=st.end();){
                if(*it > r) break;
                a[*it] = par[a[*it]];
                update(1,1,n,*it);

                if(a[*it] == 1){
                    it=st.erase(it);
                }
                else{
                    it++;
                }
            }
        }
        else{
            cout<<query(1,1,n).second<<'\n';
        }
    }
}