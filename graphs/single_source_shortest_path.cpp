#include<bits/stdc++.h>
using namespace std;
class graph{
    map<int, list<int> > l;
public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void shortestPath(int src){
        map<int ,int> vis;
        queue<int> q;
        q.push(src);

        for(auto it : l){
            int node= it.first;
            vis[node]=INT_MAX;
        }
        vis[src]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int nbr : l[node]){
                if(vis[nbr]==INT_MAX){
                    q.push(nbr);
                    vis[nbr]=vis[node]+1;
                }
            }
        }

        for(auto it : l){
            cout<<it.first<<" "<<vis[it.first]<<",";
        }
    }
    void dfs_helper(int src,map<int,bool> &vis,int a){
        cout<<src<<" ";
        vis[src]=true;
        for(int it : l[src]){
            if(vis[it]==false)
                    dfs_helper(it,vis,a+1);
        }

    }
    void dfs(int src){
        map<int,bool> vis;
        for(auto it : l){
            vis[it.first]=false;
        }
        dfs_helper(src,vis);
    }
    void connectedComponentsDFS(){
        map<int,bool> vis;
        for(auto it : l){
            vis[it.first]=false;
        }
        int cnt=1;
        for(auto it : l){
            if(!vis[it.first]){
                cout<<"component"<<cnt<<"-->";
                dfs_helper(it.first,vis);
                cnt++;
                cout<<endl;
            }
        }
    }
};

int main(){
    graph g;

    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.addEdge(6,5);
    g.addEdge(6,7);

    g.connectedComponentsDFS();
}
