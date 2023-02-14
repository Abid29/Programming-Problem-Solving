#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>> t; while(t--){
        long double r,x1,x2,y;
        cin>>r>>x1>>x2>>y;
        if(x2<x1) swap(x1,x2);
        long double y1 = sqrt(r*r-x1*x1);
        long double y2 = sqrt(r*r-x2*x2);
        y1+=y1 , y2+=y2;
        //cout<<y1<<' '<<y2<<endl;

        long double A1=0,A2=0;
        if(x1<r){
            A1 = r*r*atan(y1/(2*x1));
            long double s = (r+r+y1)/2.0;
            A1 -= sqrt(s*(s-y1)*(s-r)*(s-r));
        }
        if(x2<r){
            A2 = r*r*atan(y2/(2*x2));
            long double s = (r+r+y2)/2.0;
            A2 -= sqrt(s*(s-y2)*(s-r)*(s-r));
        }

        long double tom = A1 - A2;
        long double samron = (2*(x2-x1)*y - tom)/2.0;
        long double oditi = acos(-1.0) * r*r - tom;


        cout<<setprecision(8)<<fixed;
        cout<<oditi<<' '<<samron<<' '<<samron<<' '<<tom<<'\n';
    }
}