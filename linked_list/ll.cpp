#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};
int len(node*head){
    if(head==NULL)
        return 0;
    int c=0;
    while(head->next){
        c++;
        head=head->next;
    }
    return c+1;
}

node*mid(node*head){
    if(head==NULL || head->next==NULL)
        return head;
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

void insertHead(node*&head,int d){
    if(head==NULL){
        node* head=new node(d);
    }
    node* newNode=new node(d);
    newNode->next=head;
    head=newNode;
    return;
}

void insertTail(node*&head,int d){
    // 
    if(head==NULL){
        // cout<<"&&&";
        head=new node(d);
        return;
    }
    // cout<<head->data<<"*";
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    node* newNode= new node(d);
    tail->next=newNode;
    tail=tail->next;
    return;
}

void insertMiddle(node*&head,int d,int p){
    if(head==NULL || p==0)
        insertHead(head,d);
    if(p>len(head))
        insertTail(head,d);
    node* temp=head;
    int j=1;
    while(j<=p-1){
        temp=temp->next;
        j++;
    }
    node*newNode=new node(d);
    newNode->next=temp->next;
    temp->next=newNode;
    return;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}

void deleteHead(node*&head){
    if(head==NULL)
        return ;

    node*temp=head->next;
    delete head;
    head=temp;
    return;
}

void deleteTail(node*&head){
    if(head==NULL)
        return ;

    node*temp=head;
    while(temp->next->next){
        temp=temp->next;
    }
    // temp=temp->next;
    delete temp->next;
    temp->next=NULL;
    return;
}

void deleteMiddle(node*&head,int p){
    // cout<<len(head)<<"**";
    if(head==NULL || p<1 || p>len(head))
        return;
    if(p==1){
        deleteHead(head);
        return;
    }
    if(p==len(head)){
        deleteTail(head);
        return;
    }
    int j=1;
    node*temp=head;
    node*prev=temp;
    while(j<=p-1){
        prev=temp;
        temp=temp->next;
        j++;
    }
    prev->next=temp->next;
    delete temp;

}

bool searchLL(node*head,int key){
    if(head==NULL)
        return false;
    if(head->data==key)
        return true;
    bool f=searchLL(head->next,key);
    return f;
}

node* input(){
    int d;
    cin>>d;
    node*head=NULL;
    while(d!=-1){
        insertTail(head,d);
        cin>>d;
    }
    return head;
}

void rev(node*&head){
    node*curr=head;
    node*prev=NULL;
    node*nxt;
    // if(curr==NULL)
    //     return;
    
    while(curr){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
    //  print(head);
}
node* revRec(node*head){
    if(head==NULL || head->next==NULL)
        return head;
    node* smallHead=revRec(head->next);
    node* temp=smallHead;
    while(temp->next){
        temp=temp->next;
    }
    head->next=NULL;
    temp->next=head;
    return smallHead;
}

node*k_End(node*head,int k){
    
    if(k==0 || k>len(head))
        return NULL;
    node*fast=head;
    node*slow=head;
    int jumps=0;
    while(jumps<k){
        // cout<<len(head);
        fast=fast->next;
        // cout<<fast->data<<"*";
        jumps++;
    }
    while(fast){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

node*merge2sortedLL(node*a,node*b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    node*c;
    if(a->data < b->data){
        c=a;
        c->next=merge2sortedLL(a->next,b);
    }
    else{
        c=b;
        c->next=merge2sortedLL(a,b->next);
    }
    return c;
}

node* mergeSort(node*head){
    if(head==NULL ||head->next==NULL)
        return head;
    node*midpt=mid(head);
    node*a=head;
    node*b=midpt->next;
    midpt->next=NULL;
    a=mergeSort(a);
    b=mergeSort(b);
    node*c=merge2sortedLL(a,b);
    return c;

}

bool cycle(node*head){
    // if(len(head)<3)
    //     return false;
    node*fast=head;
    node*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            return true;
    }
    return false;
}

node* floydCycle(node*head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            slow=head;
            break;
        }
    }
    node*cycle;
    node*prev;
    while(slow!=fast){
        slow=slow->next;
        prev=fast;
        fast=fast->next;
    }
    cycle=fast;
    prev->next=NULL;
    return cycle;


}

int main(){
   
    node* head1=input();
    print(head1);
    node*tail=head1;

    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=head1->next;
    // print(head1);
    // node* head2=input();
    // print(head2);
    // int k;cin>>k;
    // node* h=new node(8);
    // insertTail(head1);
    // h->next=head1->next;
    bool ans=cycle(head1);
    if(ans){
        node* where=floydCycle(head1);
        cout<<where->data<<endl;
        print(head1);
    }
}