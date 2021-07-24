#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<char> q;
    int freq[27]={0};
    string a;
    cin>>a;

    for(int i=0;a[i]!='\0';i++){
        char ch=a[i];
        freq[ch -'a']++;
        q.push(ch);

        while(!q.empty()){
            if(freq[q.front() - 'a'] != 1){
                q.pop();
            }
            else{
                cout<<q.front()<<" ";
                break;
            }
        }     
        if(q.empty()){
            cout<<-1<<" ";
        }  
        //cin>>ch;
    }
}