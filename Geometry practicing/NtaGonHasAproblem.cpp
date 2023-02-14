#include<bits/stdc++.h>
using namespace std;
long double pi = acos(-1.0);
long double x[200],y[200];
int m;

long double dis(long double xx,long double yy){
    long double mx = 0;
    for(int i=0;i<m;i++){
        mx = max(mx,(x[i]-xx)*(x[i]-xx)+(y[i]-yy)*(y[i]-yy));
    }
    return mx;
}

long double TSy(long double xx){
    int iter = 100;
    long double l0=-111,h0=111;
    while(iter--){
        long double mid1 = (l0+l0+h0)/3;
        long double mid2 = (l0+h0+h0)/3;
        long double d1 = dis(xx,mid1);
        long double d2 = dis(xx,mid2);
        if(d1>d2) l0=mid1;
        else      h0=mid2;
    }
    return dis(xx,l0);
}

long double TSx(){
    int iter = 100;
    long double l0=-111,h0=111;
    while(iter--){
        long double mid1 = (l0+l0+h0)/3;
        long double mid2 = (l0+h0+h0)/3;
        if(TSy(mid1)>TSy(mid2)){
            l0 = mid1;
        }
        else{
            h0 = mid2;
        }
    }
    return TSy(l0);
}
int main(){
    long double n,l;
    scanf("%Lf%Lf",&n,&l);
    int i,j; scanf("%d",&m);
    for(i=0;i<m;i++) scanf("%Lf%Lf",&x[i],&y[i]);
    long double r = TSx(); r=sqrt(r); r+=r;
    //cout<<setprecision(12)<<fixed;
    long double ans = (r*tan(pi/n))/l;
    printf("%.12Lf",ans);
    return 0;
}