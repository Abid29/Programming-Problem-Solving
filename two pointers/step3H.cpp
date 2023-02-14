#include<bits/stdc++.h>
using namespace std;
int A[100010],B[100010];
int main(){
    long long n,m,s,a,b,sum=0,ans=0;
    cin>>n>>m>>s>>a>>b;
    for(int i = 1;i<=n;i++){
        cin>>A[i]; sum += A[i];
    }
    sort(A+1,A+n+1);
    for(int i = 1;i<=m;i++) cin>>B[i];
    sort(B+1,B+m+1);
    
    long long w = n*a;

    int aa=1,bb=m;
    while(w > s){
        w-=a,sum-=A[aa++];
    }

    if(aa<=n) ans = max(ans,sum);

    while(aa<=n+1 && bb>0){
        w += b,sum+=B[bb--];
        while(aa<=n&&w>s){
            w-=a,sum-=A[aa++];
        } 
        if(w>s) break;
        ans = max(ans,sum);
    }
    cout<<ans<<endl;
}