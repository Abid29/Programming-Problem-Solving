#include <bits/stdc++.h>
using namespace std;
string s,vowel = "AEIOU";
long long segt[800000][2][2],md=1e9+7;

void build(int st,int nd,int ind){
    if(st==nd){
        if(s[st] == 'H'){
            segt[ind][0][0]=segt[ind][0][1]=1;
            segt[ind][1][0]=segt[ind][1][1]=0;
        }
        else if(s[st]=='S' || s[st] == 'D'){
            segt[ind][0][0]=segt[ind][0][1]=0;
            segt[ind][1][0]=segt[ind][1][1]=1;
        }
        else{
            bool bal=0;
            for(char ch : vowel){
                if(ch == s[st]){
                    segt[ind][0][0]=0,segt[ind][0][1]=1;
                    segt[ind][1][0]=1,segt[ind][1][1]=0;
                    bal = 1;break;
                }
            }
            if(bal) return;
            if(s[st]!='?'){
                segt[ind][0][0]=1,segt[ind][0][1]=0;
                segt[ind][1][0]=0,segt[ind][1][1]=1;
            }
            else{
                segt[ind][0][0]=19,segt[ind][0][1]=6;
                segt[ind][1][0]=7,segt[ind][1][1]=20;
            }
        }
        return;
    }
    int mid = (st+nd)/2;
    build(st,mid,ind*2),build(mid+1,nd,ind*2+1);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                segt[ind][i][j] += segt[ind*2+1][i][k]*segt[ind*2][k][j];
            }
            segt[ind][i][j] %= md;
        }
    }
}

void update(int st,int nd,int ind,int idx){
    if(st==nd){
        if(s[st] == 'H'){
            segt[ind][0][0]=segt[ind][0][1]=1;
            segt[ind][1][0]=segt[ind][1][1]=0;
        }
        else if(s[st]=='S' || s[st] == 'D'){
            segt[ind][0][0]=segt[ind][0][1]=0;
            segt[ind][1][0]=segt[ind][1][1]=1;
        }
        else{
            bool bal=0;
            for(char ch : vowel){
                if(ch == s[st]){
                    segt[ind][0][0]=0,segt[ind][0][1]=1;
                    segt[ind][1][0]=1,segt[ind][1][1]=0;
                    bal = 1;break;
                }
            }
            if(bal) return;
            if(s[st]!='?'){
                segt[ind][0][0]=1,segt[ind][0][1]=0;
                segt[ind][1][0]=0,segt[ind][1][1]=1;
            }
            else{
                segt[ind][0][0]=19,segt[ind][0][1]=6;
                segt[ind][1][0]=7,segt[ind][1][1]=20;
            }
        }
        return;
    }
    if(st>idx || nd<idx) return;
    int mid = (st+nd)/2;
    update(st,mid,ind*2,idx),update(mid+1,nd,ind*2+1,idx);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            segt[ind][i][j] = 0;
            for(int k=0;k<2;k++){
                segt[ind][i][j] += segt[ind*2+1][i][k]*segt[ind*2][k][j];
            }
            segt[ind][i][j] %= md;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    
    cin>>n>>q>>s;

    build(0,n-1,1);
    cout<<segt[1][0][0]<<'\n';

    while(q--){
        int idx;
        char ch;
        cin>>idx>>ch;
        s[idx-1] = ch;
        update(0,n-1,1,idx-1);
        cout<<segt[1][0][0]<<'\n';
    }
    
}