#include <bits/stdc++.h>
using namespace std;
string res= "yes";
string query(long long int x){
    cout<<"? "<<x<<'\n';
    cin>>res;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long r=60,l=0;
    int nocnt = 0,cnt=0,yescnt=0;
    while(l+1<r){
        long long int mid;
        if(7-cnt+nocnt<4) break;
        if(nocnt==2) break;
        if(yescnt>nocnt) mid=(l+r)/2;
        else mid = (l+l+r)/3;

        res = query(mid);
        if(res == "no"){
            r=mid;
            nocnt++;
        }
        else{
            yescnt++;
            l=mid;
        }
        cnt++;
    }
    if(nocnt==2){
        for(int i=l+1;i<r&&cnt<7;i++){
            l=i;
            if(query(i)=="no") break;
        }
        cout<<"! "<<((long long)1<<l)<<'\n';
        return 0;
    }
    while(l+1<r){
        long long int mid;
        //if(7-cnt+nocnt<4) break;
        mid = (l+r)/2;

        res = query(mid);
        if(res == "no"){
            r=mid;
            nocnt++;
        }
        else{
            l=mid;
        }
        cnt++;
    }

    cout<<"! "<<((long long)1<<l)<<'\n';
    return 0;
}