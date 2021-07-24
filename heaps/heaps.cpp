#include<bits/stdc++.h>
using namespace std;
class heap{
    vector<int> v;
    int x;
    public:
    heap(int n){
        x=n;
        v.reserve(n+1);
        v.push_back(-1);
    }
    void push(int n){
        v.push_back(n);
        int idx=v.size()-1;
        int parent=idx/2;
        while(idx>1 and v[parent] > v[idx]){
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }
    void pop(){
        int heapSize=v.size()-1;
        swap(v[1],v[heapSize]);
        v.pop_back();
        heapify(1);

    }
    void heapify(int i){
        int l=2*i;
        int r=2*i+1;
        int minChild=-1;
        if(l <=v.size()-1 && v[i]> v[l]){
            minChild=l;
        }
        if(r<=v.size()-1 && v[minChild]> v[r]){
            minChild=r;
        }
        if(minChild!=-1){
            swap(v[i],v[minChild]);
            heapify(minChild);       
        }
    }
    int top(){
        return v[1];
    }
    bool empty(){
        return (v.size()-1==0);
    }

};

int main(){
    int n;
    cin>>n;
    heap h(n);
   
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        h.push(no);
    }
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
}