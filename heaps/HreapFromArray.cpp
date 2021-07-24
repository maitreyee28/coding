#include<bits/stdc++.h>
using namespace std;

void buildHeap(vector<int> &v){

    for(int i=2;i<v.size();i++){
        int id=i;
        int p=i/2;
        while(id>1 && v[id]>v[p]){
            swap(v[id],v[p]);
            id=p;
            p=p/2;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> vec;
    vec.push_back(-1);
    for(int i=1;i<=n;i++){
        int no;
        cin>>no;
        vec.push_back(no);
    }
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;

    buildHeap(vec);
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
}