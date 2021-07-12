#include<bits/stdc++.h>
using namespace std;
void addele(stack<int> &s,int ele){
    if(s.empty() || ele < s.top()){
        s.push(ele);
        return;
    }
    int tos=s.top();
    s.pop();
    addele(s,ele);
    s.push(tos);
    return;
}

void sortStack(stack<int> &s){
    if(s.empty())
        return;
    int tos=s.top();
    s.pop();
    sortStack(s);
    addele(s,tos);
    return;
}
int main(){
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(2);
    s.push(7);
    s.push(3);
    s.push(5);
    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}