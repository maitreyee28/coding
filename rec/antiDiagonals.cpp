#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > f(vector<vector<int> > v){
    cout<<"*";
    int n=v[0].size();
    vector<vector<int> > vis( n , vector<int> (n, 0));
    vector<vector<int> >ans;
    vector<int> pb;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j] == 0){
                int k=i;
                int l=j;
                pb.clear();
                while(k>=0 && l>=0){
                    vis[k][l]=1;
                    pb.push_back(v[k][l]);
                    k--;
                    l--;
                }
            ans.push_back(pb);
            }
            else continue;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int> > v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int m;cin>>m;
            v[i].push_back(m);
        }
    }
    cout<<"*";
    vector<vector<int> > ans=f(v);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}