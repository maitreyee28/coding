#include<bits/stdc++.h>
using namespace std;

void f(string s,int i){
    if(i==s.length()) return;
    if(s[i]=='p' && s[i+1]=='i'){
        cout<<" 3.14 ";
        f(s,i+2);
        return;
    }
    cout<<" "<<s[i]<<" ";
    f(s,i+1);
    return;
}
int main(){
    string s;
    cin>>s;
    f(s,0);
}