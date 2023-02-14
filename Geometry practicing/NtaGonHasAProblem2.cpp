#include<bits/stdc++.h>
using namespace std;
long double x[200],y[200];
int m;

long double dis(long double xx,long double yy){
    return (xx*xx) + (yy*yy);
}


int main(){
    long double pii = acos(-1.0);
    long double n,l;
    scanf("%Lf%Lf",&n,&l);
    int i,j; scanf("%d",&m);
    for(i=0;i<m;i++) scanf("%Lf%Lf",&x[i],&y[i]);
    
    long double p = .1,xx=0,yy=0,r;
    for(i=0;i<m;i++) xx += x[i] , yy += y[i];

    xx/=(long double)m , yy/=(long double)m;

    for(i=0;i<10000;i++){
        int id = 0;
        r = dis(xx-x[0],yy-y[0]);
        for(j=1;j<m;j++){
            long double rr = dis(xx-x[j],yy-y[j]);
            if(rr > r){
                r = rr , id = j;
            }
        }
        xx += (x[id]-xx)*p;
        yy += (y[id]-yy)*p;
        p *= .999;
    }

    r=sqrt(r),r+=r;

    long double ans = r*tan(pii/n)/l;
    printf("%.12Lf",ans);
    return 0;
}