#include<bits/stdc++.h>
using namespace std;
vector<int>pos[1000100];
int l,r;
template<typename T>
struct seg_tree
{
	int n;
	vector<T>ara;
	vector<T>Tree;
	vector<T>lazy;
	vector<bool>flag;
	
	seg_tree(int _n)
	{
		n=_n;
		ara.resize(n+1);
		Tree.resize(4*n+1);
		lazy.resize(4*n+1);
		flag.assign(4*n+1,false);
		build(1,n,1);
	}
	
	T func(T a,T b) { return a+b; }
	
	void build(int l,int r,int at)
	{
		if(l==r)
		{
			Tree[at]=ara[l];
			return;
		}
		
		int mid=(l+r)/2;
		
		build(l,mid,at*2);
		build(mid+1,r,at*2+1);
		
		Tree[at]=func(Tree[at*2],Tree[at*2+1]);
	}
	
	void update(int tL,int tR,int rL,int rR,T val,int at)
	{
		push(tL,tR,at);
		if(tL>rR || tR<rL) return;
		if(tL>=rL && tR<=rR)
		{
			lazy[at]=val;
			flag[at]=true;
			push(tL,tR,at);
			return;
		}
		
		int mid=(tL+tR)/2;
		
		update(tL,mid,rL,rR,val,at*2);
		update(mid+1,tR,rL,rR,val,at*2+1);
		
		Tree[at]=func(Tree[at*2],Tree[at*2+1]);
	}
	void update(int l,int r,T val) { update(1,n,l,r,val,1); }
	
	void push(int l,int r,int at)
	{
		if(flag[at])
		{
			Tree[at]=(lazy[at]*(r-l+1));
			if(l!=r)
			{
				lazy[at*2]=lazy[at];
				lazy[at*2+1]=lazy[at];
				flag[at*2]=true;
				flag[at*2+1]=true;
			}
			lazy[at]=0;
			flag[at]=false;
		}
	}
	
	T query(int tL,int tR,int rL,int rR,int at)
	{
		push(tL,tR,at);
		if(tL>rR || tR<rL) return 0;
		if(tL>=rL && tR<=rR) return Tree[at];
		
		int mid=(tL+tR)/2;
		
		T a=query(tL,mid,rL,rR,at*2);
		T b=query(mid+1,tR,rL,rR,at*2+1);
		
		return func(a,b);
	}
	T query(int l,int r) { return query(1,n,l,r,1); }
	
};

//initialize with seg_tree<int>st(n)
//for segment addition st.update(l,r,1)
//for segment deletion st.update(l,r,0)
//for query st.query(l,r)
int main(){
    long long int n,i,k,x;
    seg_tree<int>st(n);
    cin>>n>>k;
    for(i=1;i<=1000000;i++) pos[i].push_back(0);
    long long ans = 0;
    for(i=1;i<=n;i++){
        cin>>x;
        st.update(i,i,1);
        pos[x].push_back(i);
        int sz = pos[x].size();
        ans += i;
        
        if(sz>=k+1){
            l=pos[x][sz-k-1]+1,r=pos[x][sz-k];
            st.update(l,r,0);
        }
        if(sz>=k+2){
            l=pos[x][sz-k-2]+1,r=pos[x][sz-k-1];
            st.update(l,r,1);
        }
        cout<<i<<' '<<st.query(1,n)<<endl;
    }
    cout<<ans<<endl;
}