#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int price[n];

    for(int i=0;i<n;i++)
        cin>>price[i];
    int span[n]={0};
    stack<pair<int,int> > s;
    span[0]=1;
    s.push(make_pair(0,price[0]));
    for(int i=1;i<n;i++){
        if(price[i] < s.top().second){
            span[i]=i - s.top().first;
            s.push(make_pair(i,price[i]));         
        }
        else{
            if (s.empty())
                span[i]=i+1;
            else{
                while(price[i] > s.top().second){
                    s.pop();
                }
                span[i]=i - s.top().first;
                s.push(make_pair(i,price[i])); 
            }
            
        }
    }
    for(int i=0;i<n;i++)
        cout<<span[i]<<"  ";
}