#include<bits/stdc++.h>
using namespace std;

class graph{
    list<pair<int,int> > l;
    int v;
public:
    graph(int v){
        this->v=v;
    }
    int addEdge(int a, int b){
        l.push_back(make_pair(a,b));
    }
    int findSet(int s, int parent[]){
        if(s==-1)
            return -1;
        return parent[s]=findSet(parent[s],parent);
    }
    void unionSet(int a, int b,int parent[]){
        int s1=findSet(a,parent);
        int s2=findSet(b,parent);
        if(s1 != s2){
            parent[s2]=s1;
        }
    }
    bool isCycle(){
        int *parent=new int[v];
        for(int i=0;i<v;i++)
            parent[i]=-1;
        for(auto i : l){
            int n1=i.first;
            int n2=i.second;

            int s1=findSet(n1,parent);
            int s2=findSet(n2,parent);
            if(s1 != s2){
                unionSet(n1,n2,parent);
            }
            else
                return true;
        }
        return false;
    }

};


int main(){
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);

    cout<<g.isCycle();
}
