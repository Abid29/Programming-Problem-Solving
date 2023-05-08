#include <bits/stdc++.h>
using namespace std;
#define mx 20000001
int ndiv[mx],grundy[mx],grundysum[mx],pdiv[mx];

int main(){
    int lim = sqrt(mx);
    for(int i = 2;i<=lim;i++){
        if(pdiv[i]) continue;
        for(int j = i;j<mx;j+=i) pdiv[j] = i;
    }

    for(int i = 2;i<mx;i++) if(!pdiv[i]) pdiv[i] = i;

    ndiv[1] = 1;
    for(int i=2;i<mx;i++){
        int j=i,cnt=0;
        while(j%pdiv[i] == 0) cnt++,j/=pdiv[i];
        ndiv[i] = ndiv[j] * (cnt+1);
    }

    grundy[1] = grundysum[1] = 1;
    grundy[2] = 1;
    grundysum[2] = 2;

    for(int i=3;i<mx;i++){
        if(grundysum[i-1] - grundysum[i-ndiv[i]-1] == ndiv[i]) grundy[i] = 0;
        else                                                   grundy[i] = 1;
        grundysum[i] = grundysum[i-1] + grundy[i];
    }

    //int mx = 0;

    //for(int i = 1; i < 200001;i++) mx = max(mx,ndiv[i]);

    //cout<<mx<<endl;

    int t; scanf("%d",&t); while(t--){
        int n;
        scanf("%d",&n);
        puts(grundy[n]?"Ada":"Vinit");
    }
}