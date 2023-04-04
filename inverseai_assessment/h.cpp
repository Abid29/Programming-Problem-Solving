#include <bits/stdc++.h>
using namespace std;

long long ggcd(long long int a , long long int b){
   if(b==0) return a;
   a%=b;
   return ggcd(b,a);
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n; cin>> n; while(n--){
		long long p,q,b; cin >> p >> q >>b;
		
		long long gcd = ggcd(p,q);
		
		q /= gcd;
		
		if(q==1){
			cout<<"Finite\n";
			continue;
		}
		
		int tot = 15;
		gcd = b;
		while(q>1 && gcd > 1){
			gcd = ggcd(gcd,q);
			if(gcd <= 1) break;
			while(q%gcd ==0) q/=gcd;
		}
		
		if(q==1) cout<<"Finite\n";
		else     cout<<"Infinite\n";
		
	}
}