#include<bits/stdc++.h>
using namespace std;
int mx = 31,len = mx+1;
int main(){
    int n,i,j,k;
    cin>>n;
    int x0,y0,xt,yt;
    cin>>x0>>y0>>xt>>yt;
    for(i=1;i<=n;i++){
        int val,sal;
        cin>>val>>sal;
    }

    for(i=1;i<=y0+1;i++) puts("down");
    puts("left");
    for(i=1;i<=mx;i++) puts("down");
    puts("right");
    for(i=1;i<=mx;i++) puts("up");

    // i am in y = -1
    
    for(i=1;i<=x0;i++) puts("left");
    for(i=1;i<=mx;i++){
        for(j=-1;j<yt;j++){
            puts("up");
        }
        for(j=-1;j<yt;j++){
            puts("down");
        }
        puts("right");
    }

    // here in x=31,y=-1;

    for(j=-1;j<yt;j++){
        puts("up");
    }

    // here in x=31,y=yt

    for(j=1;j<=len;j++) puts("up");
    //len = 40;

    // here in yt = 40, xt = 31;

    for(i=1;i<len;i++){
        for(j=mx-1;j>xt;j--){
            puts("left");
            puts("down");
            puts("up");
            
        }

        //here in x=xt+1,y=yt+len;

        for(j=xt+1;j<mx;j++) puts("right");
        
        for(j=0;j<=len-i;j++) puts("down");
        for(j=mx-1;j>xt;j--) puts("left");
        for(j=xt+1;j<mx;j++) puts("right");
        for(j=1;j<=len-i;j++) puts("up");
        
    }
    //puts("right");
    for(i=2;i<=len;i++) puts("up");
    for(i=mx;i>xt;i--) puts("left");
    //puts("abid");
    for(i=len;i>0;i--) puts("down");
    for(i=len;i>0;i--) puts("up");
    for(i=xt;i>=0;i--) puts("left");

    for(i=1;i<len;i++){
        for(j=-1;j<xt-1;j++){
            puts("right");
            puts("down");
            puts("up");
            
        }

        //here in x=xt+1,y=yt+len;

        for(j=xt-1;j>-1;j--) puts("left");
        
        for(j=0;j<=len-i;j++) puts("down");
        for(j=-1;j<xt;j++) puts("right");
        for(j=-1;j<xt;j++) puts("left");
        for(j=1;j<=len-i;j++) puts("up");
        
    }

}
