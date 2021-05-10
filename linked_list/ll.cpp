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
    if(head==NULL){
        node* head=new node(d);
    }
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

int main(){
    node* head=NULL;
    insertHead(head,3);
    insertHead(head,2);
    insertHead(head,1);
    insertMiddle(head,6,2);
    insertTail(head,4);
    insertTail(head,7);
    print(head);
    cout<<endl;
    // deleteHead(head);
    // deleteTail(head);
    deleteMiddle(head,7);
    print(head);
    
    

}