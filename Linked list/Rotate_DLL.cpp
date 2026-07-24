#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *prev;
        Node *next;
        Node(int x){
            this->data=x;
            this->prev=NULL;
            this->next=NULL;
        }
};

void printLLI(Node* head){
    // iterative approach
    Node* ptr=head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void printLLR(Node *head){
    // recursive approach
    if(!head) 
        return;
    cout<<head->data<<" ";
    printLLR(head->next);
}

Node* rotateDLL(Node* head,int k){
    Node* curr=head;
    // go to last node
    while(curr->next)
        curr=curr->next;
    // make connection between first and last
    curr->next=head;
    head->prev=curr;
    // move curr till k time
    while(k--)
        curr=curr->next;
    // break and make connection
    head=curr->next;
    head->prev=NULL;
    curr->next=NULL;
    return head;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    Node *f=new Node(6);
    a->next=b;
    b->next=c;
    b->prev=a;
    c->next=d;
    c->prev=b;
    d->next=e;
    d->prev=c;
    e->prev=d;
    e->next=f;
    f->prev=e;
    printLLI(a);
    a=rotateDLL(a,2);
    printLLI(a);
}