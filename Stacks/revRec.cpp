#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int data=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(data);

}

void revRec(stack<int> &s){
    if(s.empty())
        return;

    int tos=s.top();
    s.pop();
    revRec(s);

    insertAtBottom(s,tos);
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

    stack<int> s1=s;
    while(!s1.empty()){
        int t=s1.top();
        s1.pop();
        cout<<t<<" ";
    }

    revRec(s);

    // rev(s);
    while(!s.empty()){
        int t=s.top();
        s.pop();
        cout<<t<<" ";
    }
}