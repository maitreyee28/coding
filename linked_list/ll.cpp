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

void removeDupS(node*&head){
    if(head==NULL || head->next==NULL)
        return;
    node*temp=head->next;
    node*prev=head;
    
    while(temp!=NULL && prev!=NULL){

        if(temp->data == prev->data){
            prev->next=temp->next;
            delete temp;
            temp=prev->next;
        }
        
        else{
            temp=temp->next;
            prev=prev->next;
        }
    }
    return;
}

node*removeDupUS(node*&head){
    if(head==NULL || head->next==NULL)
        return head;
    set<int> s;
    node*temp=head;
    s.insert(temp->data);
    temp=temp->next;
    node*prev=head;
    while(temp!=NULL){
        if(s.find(temp->data)!=s.end()){
            prev->next=temp->next;
            delete temp;
            temp=prev->next;
        }
        else{
            s.insert(temp->data);
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
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

node*moveLastEleToFront(node*&head){
    node*temp=head;
    if(temp==NULL || temp->next==NULL)
        return temp;
    node*prev;
    while(temp->next){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    node*front=temp;
    front->next=head;
    head=front;
    return head;
}

node*add(node*head1,node*head2){
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    node*head=NULL;
    int carry=0;
    node*temp=NULL;
    while(head1!=NULL && head2!=NULL){
        int v=(head1->data + head2->data + carry);
        carry=v/10;
        v=v%10;
        if(head==NULL){
            head=new node(v);
            temp=head;
        }
        else {
            temp->next=new node(v);
            temp=temp->next;
        }
        // print(head);
        head1=head1->next;
        head2=head2->next;
    }
    
    if(head1==NULL){
        while(head2){
            int v=(head2->data + carry) ;
        carry=v/10;
        v=v%10;
        // cout<<v<<"*";
        node*insert=new node((v));
        temp->next=insert;
        head2=head2->next;
        temp=temp->next;
        }
        if(carry){
        node*insert=new node(1);
        temp->next=insert;
        }
    }
    else if(head2==NULL){
        while(head1){
            int v=(head1->data + carry) ;
        carry=v/10;
        v=v%10;
        // cout<<v<<"*";
        node*insert=new node((v));
        temp->next=insert;
        head1=head1->next;
        temp=temp->next;

        }
        if(carry){
        node*insert=new node(1);
        temp->next=insert;
        }
    }
    

    // print(head);
    return head;
}

node*add1(node*&head){
    if(head==NULL)
        return head;
    node*temp=head;
    int carry=1;
    while(temp->next){
        if(temp->data < 9){
         temp->data=temp->data + carry;
         carry=0;
         temp=temp->next;
        }
        else{
         temp->data=0;
         carry=1;
         temp=temp->next;
        }
    }  
    if(temp->data < 9 || (temp->data==9 && carry==0)){
        temp->data=temp->data + carry;
    }
    else{
         temp->data=0;
         temp->next=new node(1);
    }
    return temp;
}
bool palindrome(node*head){
 if(head==NULL || head->next==NULL)
    return true;
 stack<int> s;
 node*temp=head;
//  node*mid_ele=mid(head);
 while(head){
     s.push(head->data);
     head=head->next;
 }
 while(temp){
     if(temp->data != s.top()){
         return false;
     }
     temp=temp->next;
     s.pop();
 }
 return true;
}

node*sort_0_1_2(node*head){
    int count[3]={0};
    cout<<count[0]<<count[1]<<count[2];
    while(head){
        count[head->data]++;
        head=head->next;
    }
    cout<<count[0]<<count[1]<<count[2];
    int i=0;
    node*ans= NULL;
    while(i<3){
        while(count[i]){
         insertTail(ans,i);
         count[i]--;
        }
        if(count[i]==0)
            i++;
    }
    return ans;
}

int intersectPoint(node* head1, node* head2)
{
    // Your Code Here
    int l1=len(head1);
    int l2=len(head2);
    if(l1>l2){
        int diff=l1-l2;
        // node*temp=head1;
        int j=1;
        while(j<=diff){
            head1=head1->next;
            
        }
        while(head1!=NULL || head2!=NULL){
            if(head1->next == head2->next)
                return head1->next->data;
            head1=head1->next;
            head2=head2->next;
        }
    }
    else{
        int diff=l2-l1;
        // node*temp=head1;
        int j=1;
        while(j<=diff){
            head2=head2->next;
        
        }
        while(head1!=NULL || head2!=NULL){
            if(head1->next == head2->next)
                return head1->next->data;
            head1=head1->next;
            head2=head2->next;
        }
    }
    
}

node*sort_odd_even(node*head){
    node*odd=NULL;
    node*odd_head=NULL;
    node*even=NULL;
    node*even_head=NULL;
    while(head!=NULL){
        // cout<<head->data;
        if((head->data) %2 ==0){
            if(even==NULL){
                even_head=head;
                even=even_head;
            }
            else{
                even->next=head;
                even=even->next;
            }

        }
        else {
            if(odd==NULL){
                odd_head=head;
                odd=odd_head;
            }
            else{
                odd->next=head;
                odd=odd->next;
            }
        }
        head=head->next;
    }
    
    even->next=odd_head;
    odd->next=NULL;
    return even_head;
}

void delGrtRt(node*head){
    if(head==NULL || head->next==NULL)
        return ;
    
    node*temp=head;
    while(temp->next!=NULL && (temp->data < temp->next->data)){
        head=temp->next;
        delete temp;
        temp=head;
    }
    node*curr=head;
    node*prev=head;
    while(curr->next !=NULL){
        cout<<"/";
        if(curr->data < curr->next->data){
            cout<<"*";
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    print(head);
}

node*k_rev(node*head, int k){
    node*curr=head;
    node*prev=NULL;
    stack<node*> s;

    while(curr!=NULL){
        int count=0;
        while(curr !=NULL && count<k){
            s.push(curr);
            curr=curr->next;
            count++;
        }
        while(s.size()>0){
            if(prev==NULL){
                prev=s.top();
                head=prev;
                s.pop();
            }
            else{
                // cout<<s.top()->data<<"*";
                prev->next=s.top();             
                prev=prev->next;
                s.pop();
            }
        }
    }
    prev->next=NULL;
    return head;
}
node*rotate(node*head,int k){
    if (head == NULL || head->next == NULL) return head;

        node* dummy = new ListNode(0);
        dummy->next = head;

        node *fast = dummy, *slow = dummy;

        int sizeOfList = 0; 
        while (fast->next != NULL) {
            fast = fast->next;
            sizeOfList++;
        }

       int firstNodePos = sizeOfList - (k % sizeOfList);
        for (int i = 0; i < firstNodePos; i++) {
            slow = slow->next;
        }

        fast->next = dummy->next;
        dummy->next = slow->next; 
        slow->next = NULL;

        return dummy->next;
}


int main(){
   
    node* head1=input();
    // print(head1);
    // node* head2=input();
    // print(head2);
    int k;cin>>k;
    node*ans=k_rev(head1,k);
    print(ans);
    // cout<<palindrome(head1);
}