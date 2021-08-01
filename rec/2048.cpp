#include<bits/stdc++.h>
using namespace std;
char spell[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void f(int n){
    if(n==0)
        return;
    f(n/10);
    int dig=n%10;
    cout<<spell[dig]<<" ";
    return;
}
int main(){
    f(2048);
}