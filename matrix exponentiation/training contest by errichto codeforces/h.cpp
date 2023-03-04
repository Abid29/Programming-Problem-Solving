#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    string ss,s,vowel = "AEIOU";
    cin>>n>>q>>ss;
    s="u"+ss;
    set<int>sw,ques,sad,happy;
    for(int i=1;i<=n;i++){
        for(char ch : vowel){
            if(ch == s[i]){
                sw.insert(i);break;
            }
        }
        if(s[i] == '?') ques.insert(i);
        else if(s[i] == 'H') happy.insert(i);
        else if(s[i]=='S'||s[i]=='D') sad.insert(i);
    }
}