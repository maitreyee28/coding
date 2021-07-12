#include<bits/stdc++.h>
using namespace std;

void transfer(stack<int> &s1,stack<int> &s2,int n){
    for(int i=0;i<n;i++){
        int store= s1.top();
        s1.pop();
        s2.push(store);
    }
}


void rev(stack<int> &s){
    int n=s.size();
    stack<int> dup;
    for(int i=0;i<n;i++){
        int storeTop=s.top();
        s.pop();

        transfer(s,dup,n-i-1);

        s.push(storeTop);

        transfer(dup,s,n-i-1);

    }

    
}

int main(){
    stack<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        s.push(no);
    }

    rev(s);
    while(!s.empty()){
        int t=s.top();
        s.pop();
        cout<<t<<" ";
    }

}