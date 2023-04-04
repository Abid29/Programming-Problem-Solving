#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,i,j;
	cin>>n;
	long long x,y;
	
	map<pair<long long,pair<int,int>>,int>mp;
	
	vector<pair<long long,long long int>>pt;
	
	for(i = 0; i < n;i++){
		cin>>x >> y;
		pt.push_back({x,y});
	}
	
	sort(pt.begin(),pt.end());
	
	for(i = 0;i < n;i++){
		x=pt[i].first,y=pt[i].second;
		for(j = i+1;j < n;j++){
			long long a = pt[j].first,b=pt[j].second;
			
			long long dis = (x-a)*(x-a)+(y-b)*(y-b);
			int ydif = y-b;
			int xdif = x-a;
			
			int gcd  = __gcd(abs(xdif),abs(ydif));
			
			ydif/=gcd;
			xdif/=gcd;
			
			mp[{dis,{xdif,ydif}}]++;
		}
	}
	
	long long ans = 0;
	
	for(auto it : mp){
		long long cnt = it.second;
		
		//cout<<cnt<<endl;
		
		ans += (cnt-1)*cnt/2;
		
	}
	
	cout<<ans/2;
	
}