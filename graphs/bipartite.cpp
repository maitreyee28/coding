#include<bits/stdc++.h>
using namespace std;
bool bipartiteHelper(int src, int parent,vector<int> graph[], int color,int *vis){
    vis[src]=color;
    for(auto it : graph[src]){
        if(vis[it]==0){
            bool check=bipartiteHelper(it,src,graph,3-color,vis);
            if(check==false)
                return false;
        }
        else if(it!=parent && color==vis[it])
            return false;
    }
    return true;
}

bool isBipartite(vector<int> graph[],int n){
    int vis[n]={0};
    int color=1;
    return bipartiteHelper(0,-1,graph,color,vis);
}



int main(){
    int n,e;
    cin>>n>>e;
    vector<int> graph[n];
    while(e--){
        int n1,n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    cout<<isBipartite(graph,n);
}
