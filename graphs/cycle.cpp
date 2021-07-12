#include<bits/stdc++.h>
using namespace std;
int ast;
class graph{
    map<int, list<int> > l;
public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool cycleHelper(int src,map<int,bool> &vis,int parent){
        vis[src]=true;
        for(auto it : l[src]){
            if(!vis[it]){
                bool isCycle=cycleHelper(it,vis,src);
                if(isCycle)
                    return true;
            }
            else if(it!=parent)
                return true;
        }
        return false;
    }
    bool isCycle(){
        map<int, bool> vis;

        for(auto it : l){
            vis[it.first]=false;
        }
        //cout<<"#";
        return cycleHelper(0,vis,-1);
    }
};
int main(){
    graph g;
    g.addEdge(0,1);
    //g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
   // cout<<g.isCycle();
   if(g.isCycle())
    cout<<"yes";
   else cout<<"no";

}
