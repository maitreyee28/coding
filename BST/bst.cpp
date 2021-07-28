#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n){
        val=n;
        left=NULL;
        right=NULL;
    } 
};

   TreeNode* insertBST(TreeNode* root, int d){

        if(root==NULL){
            return new TreeNode(d);
        }
        if(d > root->val){
            root->right=insertBST(root->right,d);
        }
        else
            root->left=insertBST(root->left,d);

        return root;
    }
    TreeNode* build(){
        int d;
        cin>>d;
        TreeNode* root=NULL;
        while(d!=-1){   
            root=insertBST(root,d);
            cin>>d;
        }
        return root;
        
    }
    void bfs(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        TreeNode* f=q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->val<<" ";
            q.pop();

            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    } 
    return;
}

bool searchBST(TreeNode* root,int n){
    if(root==NULL) return false;
    if(root->val == n) return true;
    if(n > root->val){
        return searchBST(root->right,n);
    }
    return searchBST(root->left,n);
}

TreeNode* delBST(TreeNode* root, int n){
    if(root==NULL) return NULL;

    else if(n < root->val){
        root->left=delBST(root->left,n);
        return root;
    }
    else if(root->val == n){
        //0
        if(!root->left && !root->right){
            delete(root);
            return NULL;
        }

        //1
        else if(!root->left || !root->right){
            TreeNode *temp;
            if(root->left){
                temp=root->left;
                delete(root);
                return temp;
            }
            temp=root->right;
            delete(root);
            return temp;
        }

        //2
        else{
            TreeNode* nextRoot=root->right;
            while(nextRoot->left != NULL){
                nextRoot=nextRoot->left;
            }
            swap(root->val , nextRoot->val);
            root->right = delBST(root->right,n);
            return root;
        }

    }
    else{
        root->right=delBST(root->right,n);
        return root;
    }
}

bool isBST(TreeNode* root,int minV, int maxV){
    if(root==NULL) return true;
    if(root->val >= minV && root->val <= maxV && isBST(root->left,minV,root->val) && isBST(root->right,root->val,maxV)){
        return true;
    }
    return false;
}

void populateInoSucc(TreeNode* root,int parent){
    if(root==NULL) return;
    populateInoSucc(root->left,root->val);
    
    if(!root->right){
        cout<<root->val<<" -> "<<parent<<endl;
        return;
    }
    TreeNode* nextRoot=root->right;
        while(nextRoot->left != NULL){
            nextRoot=nextRoot->left;
        }
    cout<<root->val<<" -> "<<nextRoot->val<<endl;
    populateInoSucc(root->right,parent);
    return;
}

TreeNode* flattenBST(TreeNode* root){

}

TreeNode* LCA(TreeNode* root,int n1,int n2){
    if(root==NULL) return NULL;

    if(root->val > n1 && root->val > n2)
        return LCA(root->left,n1,n2);

    if(root->val < n1 && root->val < n2)
        return LCA(root->right,n1,n2);

    return root;
    
}

void inOrderBSTfromBT(TreeNode* root, vector<int> &v){
    if(root==NULL) return;

    inOrderBSTfromBT(root->left ,v);
    v.push_back(root->val);
    inOrderBSTfromBT(root->right,v);
    return;
}
void inOrderBSTfromBT2(TreeNode* root,vector<int> &v,int &i){
    if(root==NULL) return;

    inOrderBSTfromBT2(root->left ,v,i);
    root->val=v[i];
    i++;
    inOrderBSTfromBT2(root->right,v,i);
    return;
}
TreeNode* BSTfromBT(TreeNode* root){
    vector<int> v;
    inOrderBSTfromBT(root,v);
    sort(v.begin(),v.end());
    int i=0;
    inOrderBSTfromBT2(root,v,i);
    return root;
}

TreeNode* heightBalBSTUtil(vector<int> &v,int s,int e){

    if(s>e) return NULL;
    int mid=(s+e)/2;
    TreeNode* root=new TreeNode(v[mid]);
    root->left=heightBalBSTUtil(v,s,mid-1);
    root->right=heightBalBSTUtil(v,mid+1,e);
    return root;
}

TreeNode* heightBalBST(TreeNode* root){
    vector<int> v;
    inOrderBSTfromBT(root,v);
    return heightBalBSTUtil(v,0,v.size()-1);
}
set<pair<int, int> > s;
void sumfn(TreeNode* root1,TreeNode* root2, int k){
    if(root1==NULL || root2==NULL) return ;
    int sum=root1->val + root2->val;
    
    int s1,s2;
    if(sum==k) {
       s.insert(make_pair(root1->val,root2->val));
       sumfn(root1->right,root2->left,k);
       sumfn(root1->left,root2->right,k);
    }
    if(sum > k){
       sumfn(root1,root2->left,k);
       sumfn(root1->left,root2,k);
    }
    if(sum < k){
       sumfn(root1,root2->right,k);
       sumfn(root1->right,root2,k);
    }
}
int nodes=0;
void inRange(TreeNode* root,int n, int m){
    if(root==NULL) return;
    if(root->val >=n && root->val <=m){
        nodes++;
        inRange(root->left,n,m);
        inRange(root->right,n,m);
    }
    if(root->val > m){
        inRange(root->left,n,m);
    }
    if(root->val < n){
        inRange(root->right,n,m);
        
    }
    return;
}
vector<vector<int> > v;
void sumPathRootLeaf(TreeNode* root,int target,vector<int> path){

    if(root==NULL) return;
    path.push_back(root->val);
    cout<<root->val<<endl;
    int sum=target - root->val;
    if(sum==0 && root->left == NULL && root->right ==NULL){
        v.push_back(path);
        cout<<"***"<<endl;
        return;
    }
    
    
    if(sum > 0){      
        sumPathRootLeaf(root->left,sum,path);
        sumPathRootLeaf(root->right,sum,path);
    }
    path.pop_back();
    return;
}

bool findsumpair(TreeNode* root,int n){
    if(root==NULL) return false;
    int rem= n - root->val;
    if(rem > root->val)
        bool r=findsumpair(root->right,rem);
    else{
        bool l=findsumpair(root->left,rem);
    }
    
}

int main(){
    TreeNode *root=build();
    vector<int> path;
    sumPathRootLeaf(root,9,path);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
    }
    cout<<endl;
}