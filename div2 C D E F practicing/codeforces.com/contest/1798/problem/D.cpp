#include <bits/stdc++.h>
using namespace std;
long long int a[300100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;while(t--){
        int n,i;cin>>n;
        multiset<long long int>ml;
        for(i=1;i<=n;i++){
            cin>>a[i];
            ml.insert(a[i]);
        }

        long long int val = *ml.rbegin() - *ml.begin(),sum=0;

        vector<int>ans;

        while(ml.empty()==0){
            auto it = ml.lower_bound(val-sum);
            if(it == ml.begin()) break;

            it--;
            sum += *it;
            ans.push_back(*it);

            ml.erase(it);
        }

        if(ml.empty()){
            cout<<"Yes\n";
            for(int element : ans){
                cout<<element<<' ';
            }
            cout<<endl;
        }
        else{
            cout<<"No\n";
        }
    }
}