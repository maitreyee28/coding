#include<bits/stdc++.h>
using namespace std;
void f(char s[],char op[],int i,int j){
    if(s[i]=='\0'){
        op[j]='\0';
        cout<<op;
        cout<<endl;
        return;
    }
    op[j]=s[i];
    f(s,op,i+1,j+1);
    f(s,op,i+1,j);
}
int main(){
    char n[100];
    cin>>n;
    char op[100];
    f(n,op,0,0);
}