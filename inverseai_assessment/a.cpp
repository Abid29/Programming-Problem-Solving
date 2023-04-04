#include <bits/stdc++.h>
using namespace std;
long long n,m,x[1010],a[1010],b[1010],c[1010],d[1010];
int main() {
	int t,t1=1; cin>>t; while(t--){
		
		cin>>n>>m;
		
		for(int i=1;i<=n;i++){
			cin>>x[i]>>a[i]>>b[i]>>c[i]>>d[i];
		}
			
		long long l = 0, r= m+1;
		
		while(l+1<r){
			long long mid = (l+r)/2;
			
			long long tot = 0;
			
			for(int i= 1;i<=n;i++){
				long long need = mid * x[i];
				
				long long cnt = 1e9;
					
				for(long long j = 0;j<101;j++){
					if(j*b[i] > need) cnt = min(cnt,j*a[i]);
					else cnt = min(cnt,j*a[i]+ ((need - j*b[i]+d[i]-1)/d[i])*c[i]);
				}
				
				for(long long j = 0;j<101;j++){
					if(j*d[i] > need) cnt = min(cnt,j*c[i]);
					else cnt = min(cnt,j*c[i]+ ((need - j*d[i]+b[i]-1)/b[i])*a[i]);
				}
				tot += cnt;
				
			}
			
			//cout<<tot << ' '<< mid<<endl;
			
			if(tot > m) r = mid;
			else          l = mid;
		}
		
		cout<<"Case "<<t1++<<": "<<l<<'\n';
	}
		
		
}