#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int d;
    node*lc;
    node*rc;

    node(int data){
        d=data;
        lc=NULL;
        rc=NULL;
    }
};

node* buildTree(){
    int n;
    cin>>n;
    if(n==-1) return NULL;
    node* root = new node(n);

    root->lc=buildTree();
    root->rc=buildTree();

    return root;
}

void printPre(node* root){
    if(root==NULL) return;
    cout<<root->d<<"  ";
    printPre(root->lc);
    printPre(root->rc);
}

int height(node*root){
    if(root==NULL) return 0;
    int lh=height(root->lc);
    int rh=height(root->rc);
    return max(lh,rh)+1;
}

void levelK(node*root,int currLevel,int k){
    if(root==NULL) return;
    if(currLevel==k){
        cout<<root->d<<" ";
        return;
    }
    levelK(root->lc,currLevel-1,k);
    levelK(root->rc,currLevel-1,k);
    return;
}

void bfs(node* root){
    queue<node*>q;
    q.push(root);

    while (!q.empty()){
        cout<<q.front()->d<<" ";
        
        if(q.front()->lc)
            q.push(q.front()->lc);
        if(q.front()->rc)
            q.push(q.front()->rc);
        
        q.pop();
        // cout<<endl;
    }
    
}

int count(node* root){
    if(root==NULL) return 0;
    return 1+ count(root->lc)+count(root->rc);
   
}
int sum(node* root){
    if(root==NULL) return 0;
    return root->d + sum(root->lc)+sum(root->rc);
   
}

int diameter(node* root){
    if(root==NULL) return 0;
    int h1=height(root->lc);
    int h2=height(root->rc);
    int op1=h1+h2;
    int op2=diameter(root->lc);
    int op3=diameter(root->rc);
    return max(op1,max(op2,op3));
}

pair<int,int> diameterOptimized(node* root){
    //height, diameter
    pair<int,int> p;
    if (root==NULL) return make_pair(0,0);
    
    pair<int,int>left =diameterOptimized(root->lc);
    pair<int,int>right =diameterOptimized(root->rc);

    p.first=max(left.first,right.first) + 1;

    p.second=max((left.first + right.first),max(left.second , right.second));
    return p;
    
}

int replaceSum(node*root){
    if(root==NULL) return 0;

    if(root->lc == NULL && root->rc==NULL)
        return root->d;
    
    int leftSum=replaceSum(root->lc);
    int rightSum=replaceSum(root->rc);

    int temp=root->d;
    root->d=leftSum+rightSum;

    return root->d + temp;
}


pair<int,int> balanced(node*root){
    //height,balanced or not bool
    pair<int,int> p;
    if(root==NULL) return make_pair(0,true);

    pair<int,int> left=balanced(root->lc);
    pair<int,int>right=balanced(root->rc);

    p.first=max(left.first,right.first) + 1;
    if(abs(left.first - right.first)<=1 && left.second && right.second){
        p.second=true;
    }
    else p.second=false;

    return p;
}

node* buildBTfromArr(int a[], int s,int e){
    if(s>e) return NULL;

    int mid=(s+e)/2;
    node* root=new node(a[mid]);
    root->lc=buildBTfromArr(a,s,mid-1);
    root->rc=buildBTfromArr(a,mid+1,e);
    return root;

}
int maxLevel=-1;
void rightView(node* root,int level){
    if(root==NULL) return ;
    if(level>maxLevel){
        cout<<root->d<<"  ";
        maxLevel = level;
    }
    rightView(root->rc,level+1);
    rightView(root->lc,level+1);
}

void topView(node*root){

}
void distKHelper(node* root,int k){
    if(root==NULL) return;
    if(k==0){
        cout<<root->d<<" ";
        return;
    }
    distKHelper(root->lc,k-1);
    distKHelper(root->rc,k-1);
    return;

}
int disKfromNode(node*root,node*t,int k){
    if(root==NULL) return -1;

    if(root==t){
        distKHelper(root,k);
        return 0;
    }

    int left=disKfromNode(root->lc,t,k);
    if(left!=-1){
        if(left+1==k){
            cout<<root->d<<" ";
        }
        else{
           distKHelper(root->rc,k-2-left); 
        }
        return 1+left;
    }
    int right=disKfromNode(root->rc,t,k);
    if(right!=-1){
        if(right+1==k){
            cout<<root->d<<" ";
        }
        else{
           distKHelper(root->lc,k-2-right); 
        }
        return 1+right;
    }
    return -1;
}

node* inPre(int in[],int pre[],int s,int e){
    static int i=0;
    if(s>e) return NULL;
    node* root=new node(pre[i]);
    int ind=-1;
    for(int j=s;j<=e;j++){
        if(in[i]==pre[j]){
            ind=j;
            break;
        }
    }
    root->lc=inPre(in,pre,s,ind-1);
    root->rc=inPre(in,pre,ind+1,e);

    return root;
}

node* LCA(node* root,int n1,int n2){
    if(root==NULL) return NULL;

    if(root->d == n1 || root->d == n2){
        return root;
    }

    node* left=LCA(root->lc,n1,n2);
    node* right=LCA(root->rc,n1,n2);

    if(right && left) return root;
    if(!right) return left;
    return right;
}
void kthAncestorHelper(node* root,int a[]){
    a[root->d]=-1;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* t=q.front();
        q.pop();
        if(t->lc){
            q.push(t->lc);
            a[t->lc->d]=t->d;
        }
        if(t->rc){
            q.push(t->rc);
            a[t->rc->d]=t->d;
        }
    }
}
int kthAncestor(node* root,int k,int n){
    int a[20]={0};
    kthAncestorHelper(root,a);
    int c=0;
    while(n!=-1){
        n=a[n];
        c++;
        if(c==k)
        break;
    }
    return n;
}
//try out stack approach as well
node* kthAncestorRec(node*root, int n,int& k){

}


int ans=INT_MIN;
int maxSumPath(node* root){
    if(root==NULL) return 0;

    int left=maxSumPath(root->lc);
    int right=maxSumPath(root->rc);

    int branch=max(max(left,right) + root->d ,root->d);
    // cout<<branch<<"**";
    int tree=max(branch , left + right + root->d);

    ans=max(ans,tree);
    // cout<<ans<<"*";
    return branch;
}

int levelkey(node* root, int key, int level){
    if(root==NULL) return -1;

    if(root->d == key) return level;

    int left=levelkey(root->lc,key,level+1);
    if(left!=-1){
        return left;
    }

    return levelkey(root->rc,key,level+1);

}

node* mirror(node* root){
    if(root==NULL) return root;

    node* t=root->lc;
    root->lc=root->rc;
    root->rc=t;

    if(root->lc) mirror(root->lc);
    if(root->rc) mirror(root->rc);

    return root;
}
void print(vector<int> v,int j){
    for(int i=j;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}


void kSumPath(node* root,int k,vector<int> &v){
    if(root==NULL) return;
    // for(int i=0;i<v.size();i++)
    //     cout<<v[i]<<" ";
    // cout<<endl;

    // cout<<root->d<<" ";
    v.push_back(root->d);
    kSumPath(root->lc,k,v);
    kSumPath(root->rc,k,v);
 
    int sum=0;
    for(int i=v.size()-1;i>=0;i--){
        sum+=v[i];
        if(sum==k)
            print(v,i);
    }
    v.pop_back();
}

int maxSubarrSum(node* root, int &ans){
    if(root==NULL) return 0;

    int nextSum=root->d + maxSubarrSum(root->lc,ans) +maxSubarrSum(root->rc,ans);
    ans=max(ans,nextSum);
    cout<<ans<<endl;
    return nextSum; 
}
int ansSum=INT_MIN;
// int sum=0;
int sumLongestPath(node* root,int lvl,int h,int sum){

    // cout<<1 2 7 -1 -1 1 -7 -1 -1 -1 5 -1 -1 "*";
    if(root==NULL){
        if(lvl==h){
            ansSum=max(ansSum,sum);
        }
        return sum;
    }
    int left=sumLongestPath(root->lc,lvl+1,h,sum + root->d);
    int right=sumLongestPath(root->rc,lvl+1,h,sum + root->d);
}
int main(){
    node* root =buildTree();
    // bfs(root);
    // cout<<endl;
    // bfs(mirror(root));
    // maxSumPath(root);
    // cout<<ans;
    // int n1,n2;
    // cin>>n1>>n2;
    // node* c=LCA(root,n1,n2);
    // cout<<levelkey(c,n1,0) + levelkey(c,n2,0);
    // vector<int> v;
    // kSumPath(root,8,v);
    // int ans=INT_MIN;
    // maxSubarrSum(root,ans);
    int h=height(root);
    sumLongestPath(root,0,h,0);
    cout<<ansSum;
}

