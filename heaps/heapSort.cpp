#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& v,int i){
        int l=2*i;
        int r=2*i+1;
        int minChild=i;
        if(l <=v.size()-1 && v[i]< v[l]){
            minChild=l;
        }
        if(r<=v.size()-1 && v[minChild]<v[r]){
            minChild=r;
        }
        if(minChild!=i){
            swap(v[i],v[minChild]);
            heapify(v,minChild);       
        }
    }
void buildHeap(vector<int> &v){
    for(int i=v.size()/2;i>=1;i--){
        heapify(v,i);
    }
}
void heapSort(vector<int> &v){
    buildHeap(v);
    int n=v.size()-1;

    while(n>1){
        swap(v[1],v[n-1]);
        n--;
        heapify(v,1);
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

    // buildHeap(vec);
    heapSort(vec);

    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
}
