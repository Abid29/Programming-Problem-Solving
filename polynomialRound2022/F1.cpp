#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD1=1e9+7;
const int MOD2=988244353;

ll add(ll a,ll b,ll MOD)
{
    return (a+b)%MOD;
}

ll mul(ll a,ll b,ll MOD)
{
    return (a*b)%MOD;
}

ll power(ll b,ll n,ll MOD)
{
    ll ans=1;
    for(;n>0;n/=2)
    {
        if(n%2) ans=mul(ans,b,MOD);
        b=mul(b,b,MOD);
        n/=2;
    }
    return ans;
}

struct Hash
{
    ll a,b;

    Hash(ll _a=0,ll _b=0) { a=_a; b=_b; }

    Hash operator + (Hash other)
    {
        Hash ans;
        ans.a=add(a,other.a,MOD1);
        ans.b=add(b,other.b,MOD2);
        return ans;
    }
    Hash operator * (Hash other)
    {
        Hash ans;
        ans.a=mul(a,other.a,MOD1);
        ans.b=mul(b,other.b,MOD2);
        return ans;
    }
    bool operator == (const Hash other) const
    {
        if(a!=other.a) return false;
        if(b!=other.b) return false;
        return true;
    }
};

const int mx=1e6+15;
const int N=1e6+2;
const Hash BASE=Hash(31,47);

Hash pwr[mx],inv[mx];

int sz[505][505];
string s[505][505];
vector<Hash>pre[505][505];

void solve()
{
    pwr[0]=Hash(1,1);
    for(int i=1;i<mx;i++) pwr[i]=pwr[i-1]*BASE;
    inv[mx-1].a=power(pwr[mx-1].a,MOD1-2,MOD1);
    inv[mx-1].b=power(pwr[mx-1].b,MOD2-2,MOD2);
    for(int i=mx-2;i>=0;i--) inv[i]=inv[i+1]*BASE;
    
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>s[i][j];

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j)
    {
        int m=s[i][j].size();
        sz[i][j]=m;
        s[i][j]='.'+s[i][j];
        pre[i][j].resize(m+1);
        pre[i][j][0]=Hash();
        for(int k=1;k<=m;k++) 
        {
            char c=s[i][j][k]-'a'+1;
            pre[i][j][k]=pre[i][j][k-1]+Hash(c,c)*pwr[N-k-1];
        }
    }

    cerr<<"hello"<<endl;

    vector<int>possible_ans(n+1);

    for(int i=1;i<=n;i++)
    {
        vector<int>to_check;
        for(int j=1;j<=n;j++) if(i!=j) to_check.push_back(j);

        cout<<"ekhane"<<endl;

        vector<int>match;
        match.push_back(sz[i][to_check[0]]);
        
        for(int j=1;j<n;j++)
        {
            int x=to_check[j-1];
            int y=to_check[j];

            int lo=1;
            int hi=min(sz[i][x],sz[i][y]);
            int pos=0;

            while(hi>=lo)
            {
                int mid=(hi+lo)/2;

                Hash a=pre[i][x][mid];
                Hash b=pre[i][y][mid];

                if(a==b)
                {
                    pos=mid;
                    lo=mid+1;
                }
                else hi=mid-1;
            }

            match.push_back(pos);
        }

        possible_ans[i]=*min_element(match.begin(),match.end());

        if(possible_ans[i]==0)
        {
            cout<<"NONE";
            return;
        }
    }

    int indx=1;
    for(int i=1;i<=n;i++) if(possible_ans[i]<possible_ans[indx])
    {
        indx=possible_ans[i];
    }

    int paisi=0;
    int len=-1;

    for(int match=possible_ans[indx];match>=1;match--)
    {
        bool good=true;

        vector<int>new_size(n+1);
        new_size[indx]=match;
        for(int i=1;i<=n;i++) if(i!=indx) new_size[i]=sz[indx][i]-match;
        vector<Hash> temp_str(n+1);
        for(int i=1;i<=n;i++)
        {
            int j=(i==1?2:1);
            temp_str[i]=pre[i][j][new_size[i]];
        }

        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j)
        {
            Hash a=temp_str[i];
            Hash b=temp_str[j]*inv[new_size[i]];
            
            Hash check_str=a+b;

            good&=(check_str==pre[i][j][sz[i][j]]);
        }

        if(good)
        {
            paisi++;
            len=match;
        }

    }

    if(paisi==0) cout<<"NONE";
    else if(paisi>1) cout<<"MANY";
    else
    {
        cout<<"UNIQUE\n";
        //cout<<
    }
}
int main()
{
    freopen("input.txt","r",stdin);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
}