#include<bits/stdc++.h>
using namespace std;

class graph{
    unordered_map<int,list<pair<int,int> > > l;
    public:
        void addEdge(int x, int y, bool bdir, int wt){
            l[x].push_back(make_pair(y,wt));
            if(bdir)
              l[y].push_back(make_pair(x,wt));
        }

        void printList(){
            for(auto p : l){
                int node=p.first;
                list<pair<int,int> > nbrs=p.second;
                cout<<node<<"->";
                for(auto i : nbrs){
                    int dest=i.first;
                    int dist=i.second;

                    cout<<dest<<" "<<dist<<",";
                }
                cout<<endl;
            }
        }
        void bfs(int src){
            queue<int> q;
            int vis[10]={0};
            q.push(src);
            vis[src]=1;
            while(!q.empty()){
                int f=q.front();
                cout<<f<<"->";
                q.pop();
                for(auto i : l[f] )
                if(!vis[i.first]){
                    q.push(i.first);
                    vis[i.first]=1;
                }
            }
        }
};

int main(){
    graph g;

    g.addEdge(0,1,true,30);
    g.addEdge(0,3,true,30);
    g.addEdge(1,2,true,30);
    g.addEdge(2,3,true,30);
    g.addEdge(3,4,true,30);
    g.addEdge(4,5,true,30);

    g.bfs(0);
    //g.printList();


}
