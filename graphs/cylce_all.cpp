#include<bits/stdc++.h>
using namespace std;

class graph{
    map<int,list<int> >m;
public:
    /*void addEdgeUD(int x,int y){
        m[x].push_back(y);
        m[y].push_back(x);
    }
    bool cycleHelperUD(int src, map<int,bool> &vis,int parent){
        vis[src]=true;
        for(auto it : m[src]){
            if(!vis[it]){
                bool cycleHai=cycleHelperUD(it,vis,src);
                if(cycleHai)
                    return true;

            }
            else if(it!=parent)
                    return true;
        }
        return false;
    }

    bool cycleUD(){
        map<int,bool> vis;
        for(auto it : m){
            vis[it.first]=false;
        }
        return cycleHelperUD(0,vis,-1);

    }*/
    void addEdgeD(int x,int y){
        m[x].push_back(y);
        //m[y].push_back(x);
    }
    bool cycleDirected(){
        map<int, bool> currStack;
        map<int,bool> vis;

        for(auto it : m){
            currStack[it.first]=false;
            vis[it.first]=false;

        }

        return CycleHelperD(vis,currStack,0);


    }
    bool CycleHelperD(map<int,bool> &vis, map<int,bool> &currStack,int node){
        vis[node]=true;
        currStack[node]=true;

        for(auto it : m[node]){
            if(currStack[it])
                return true;
            else if(vis[node]){
                bool cyclemila=CycleHelperD(vis,currStack,it);
                if(cyclemila)
                    return true;
            }
        }


        currStack[node]=false;
        return false;

    }

    void printList(){
            for(auto p : m){
                int node=p.first;
                list<int> nbrs=p.second;
                cout<<node<<"->";
                for(auto i : nbrs){
                    //int dest=i.first;
                    //int dist=i.second;

                    cout<<i<<",";
                }
                cout<<endl;
            }
        }

};

int main(){
    graph g;
    g.addEdgeD(0,1);
    g.addEdgeD(1,2);
    g.addEdgeD(2,3);
    g.addEdgeD(3,4);
    g.addEdgeD(4,2);
    g.printList();
   // cout<<g.isCycle();
   if(g.cycleDirected())
    cout<<"yes";
   else cout<<"no";

}
