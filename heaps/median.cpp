#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> lh;
    priority_queue<int,vector<int>,greater<int> > rh;
    int n;
    cin>>n;
    lh.push(n);
    float median=n;
    cout<<n<<"--> "<<median<<endl;
    cin>>n;
    while(n!=-1){
        if(lh.size()>rh.size()){
            if(n>median){
                rh.push(lh.top());
                lh.pop();
                lh.push(n);
            }
            else{
                rh.push(n);
            }
            median=(lh.top()+rh.top())/2;
        }
        else if(lh.size()==rh.size()){
            if(n<median){
                lh.push(n);
                median=lh.top();
            }
            else{
                rh.push(n);
                median=rh.top();
            }
        }
        else{
             if(n>median){
                lh.push(rh.top());
                rh.pop();
                rh.push(n);
            }
            else{
                lh.push(n);
            }
            median=(lh.top()+rh.top())/2;
        }
    cout<<n<<"--> "<<median<<endl;
    cin>>n;
    }
}