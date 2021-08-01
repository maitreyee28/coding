#include<bits/stdc++.h>
using namespace std;
void f(int n,char op[],int i,int open,int close){
    if(i== 2*n){
        op[i]='\0';
        cout<<op<<endl;
        return;
    }
   if(open<n){
       op[i]='(';
       f(n,op,i+1,open+1,close);
   }
   if(close<open){
       op[i]=')';
       f(n,op,i+1,open,close+1);
   }
   return;
   
}
int main(){
    int n;
    cin>>n;
    char a[100];
    f(n,a,0,0,0);
}