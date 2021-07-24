#include<bits/stdc++.h>
using namespace std;
vector<int> f(vector<int> a,vector<int> b,int c){
    // cout<<"*";
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    set<pair<int,int> > s;
    priority_queue<pair<int,pair<int,int> > > pq;

    int n=a.size();
    pq.push(make_pair(a[n-1]+b[n-1] ,make_pair(n-1,n-1)));
    s.insert(make_pair(n-1,n-1));
    vector<int> ans;
    
    for(int i=0;i<c;i++){
        cout<<"*";
        pair<int, pair<int, int> > temp = pq.top();
        pq.pop();
        ans.push_back(temp.first);
        int ai = temp.second.first;
        int bi = temp.second.second;

        int sum1=a[ai-1]+b[bi];
        pair<int,int> p=make_pair(ai-1,bi);
        if(s.find(p)==s.end()){
            pq.push(make_pair(sum1,p));
            s.insert(p);
        }

        int sum2=a[ai]+b[bi-1];
        p=make_pair(ai,bi-1);
        if(s.find(p)==s.end()){
            pq.push(make_pair(sum2,p));
            s.insert(p);
        }
    }

}
int main(){
    vector <int> a,b;
    a.push_back(1);
    a.push_back(4);
    a.push_back(2);
    a.push_back(3);

    b.push_back(2);
    b.push_back(5);
    b.push_back(1);
    b.push_back(6);


    int c;
    cin>>c;
    vector<int> ans= f(a,b,c);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}