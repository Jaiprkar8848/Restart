#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int x){
            this->data=x;
            this->next=NULL;
        }
};

void removeloop(Node* head){
    Node *slow,*fast;
    slow=fast=head;
    bool loop=0;
    // check whether loop is there or not
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            loop=1;
            break;
        }
    }
    if(loop==0)
        return;
    // find the start of loop
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    // now both fast and slow at start of loop
    // now move any one of them
    while(fast->next!=slow)
        fast=fast->next;
    fast->next=NULL;
}

void printLL(Node* head){
    Node* ptr=head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main(){
    Node *a=new Node(5);
    Node *b=new Node(10);
    Node *c=new Node(15);
    Node *d=new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=b;
    Node* A=a;
    removeloop(A);
    printLL(A);
}