#include<bits/stdc++.h>
using namespace std;

class graph{
    map<int,list<int> >l;
public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs(){
        map<int,bool> vis;
        for(auto i : l){
            vis[i.first]=false;
        }
        int c=1;
        for(auto i : l){
            if(!vis[i.first]){
                cout<<"Component : "<<c<<endl;
                dfs_helper(i.first,vis);
                c++;
            }
        }
    }
    void dfs_helper(int src,map<int,bool> &vis){
        cout<<src<<" ";
        vis[src]=true;
        for(auto i : l[src]){
            if(!vis[i]){
                dfs_helper(i,vis);
            }
        }
    }
};

int main(){
    graph g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(2,3);
    //g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs();
}
