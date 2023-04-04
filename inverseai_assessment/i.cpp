#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t; while(t--){
		long long n,k,d1,d2;
		cin>>n>>k>>d1>>d2;
		
		int a,b,c;
		a = d1, b = 0, c = d2;
		
		if(n%3!=0){
			puts("no");
			continue;
		}
		else if(d1 > k){
			puts("no");
			continue;
		}
		
		else if(d2>k){
			puts("no");
			continue;
		}
		
		else if(d1 == k&&d2!=k&&d2!=0){
			puts("no");
			continue;
		}
		
		else if(d2 == k && d1!=k && d1 !=0){
			puts("no");
			continue;
		}
		
		if((k-d1-d2)>=0&&(k-d1-d2)%3==0){
			if(d1>d2){
				if((n-k-d1-(d1-d2))>=0&&(n-k-d1-(d1-d2))%3 == 0){
					puts("yes");
					continue;
				}
			}
			else{
				if((n-k-d2-(d2-d1))>=0&&(n-k-d2-(d2-d1))%3 == 0){
					puts("yes");
					continue;
				}
			}
			
		}
		
		if((k-(d1+d1+d2))>=0&&(k-(d1+d1+d2))%3==0){
			long long val = d2+d2+d1;
			if((n-k-val)>=0 && (n-k-val)%3==0){
				puts("yes");
				continue;
			}
		}
		
		if((k-(d1+d2+d2))>=0&&(k-(d1+d2+d2))%3==0){
			long long val = d2+d1+d1;
			if((n-k-val)>=0 && (n-k-val)%3==0){
				puts("yes");
				continue;
			}
		}
		
		if(d1>d2){
			long long val = d1+d1-d2;
			if(k>=val && (k-val)%3==0){
				if((n-k-d1-d2)>=0&&(n-k-d1-d2)%3==0){
					puts("yes");
					continue;
				}
			}
			
			
		}
		else{
			long long val = d2+d2-d1;
			if(k>=val && (k-val)%3==0){
				if((n-k-d1-d2)>=0&&(n-k-d1-d2)%3==0){
					puts("yes");
					continue;
				}
			}
		}
		
		puts("no");
		
		
		
		
		
		
	}
}