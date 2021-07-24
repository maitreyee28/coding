#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> >node;
vector<int> f(vector<vector<int> >a){
    priority_queue<node,vector<node>,greater<node> >pq;
    vector<int> ans;
    for(int i=0;i<a.size();i++)
        pq.push({a[i][0] , {i,0}});

    while(!pq.empty()){
        node curr=pq.top();
        int ele=curr.first;
        int row=curr.second.first;
        int col=curr.second.second;
        pq.pop();
        ans.push_back(ele);

        if(col+1<a[row].size()){
            pq.push({a[row][col+1],{row,col+1}});
        }
    }
    return ans;

}
int main(){
    vector<vector<int> > arr{{2,7,9},{1,3,8},{4,5,6}};
    vector<int> ans=f(arr);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
