#include<bits/stdc++.h>
using namespace std;
int ast;
class moon{
    map<int, list<int> > l;
public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    int dfs(){
        map<int,bool> vis;
        for(auto it : l){
            vis[it.first]=false;
        }
        int countries=0;
        int sub=0;
        for(auto it : l){
            if(!vis[it.first]){
                int asts=0;
                dfs_helper(it.first,vis,asts);
                sub+=ncr(asts,2);
                countries++;
            }
        }
       // cout<<"*"<<countries<<"**"<<ncr(countries,2);
        return ncr(ast,2)-sub;
    }
     void dfs_helper(int src,map<int,bool> &vis,int &a){
        vis[src]=true;
        a++;
        for(int it : l[src]){
            if(vis[it]==false){
                 dfs_helper(it,vis,a);
            }
        }
    }
    int ncr(int n,int r){
        return fact(n) / (fact(r) * fact(n - r));
    }
    int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
};

int main(){


    cin>>ast;
    int n;
    cin>>n;
    moon g;
    while(n--){
        int n1,n2;
        cin>>n1>>n2;
        g.addEdge(n1,n2);
    }
    cout<<g.dfs();
}
