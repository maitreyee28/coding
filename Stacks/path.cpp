#include<bits/stdc++.h>
using namespace std;

string f(string s){
    stack<string> stk;
    string temp,ans;
    ans.append("/");
    int n=s.length();
    int i=0;
    while(i<s.length()){
        temp.clear();
        while(s[i]!='/')
            i++;
        while(i<n && s[i]!='/')  {
            temp.push_back(s[i]);
            i++;
        }
        if(temp.compare("..")==0){
            if(!stk.empty())
                stk.pop();
        }
        else if(temp.compare(".")==0)
            continue;
        else if(temp.length()!=0)
            stk.push(temp);
    }
    stack<string> stk2;
    while(!stk.empty()){
        stk2.push(stk.top());
        stk.pop();
    }
    while(!stk2.empty()){
        string t=stk2.top();
        if(stk2.size()==1)
            ans.append(t+"/");
        else
            ans.append(t);

        stk2.pop();
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    string ans=f(s);
    cout<<ans;
}