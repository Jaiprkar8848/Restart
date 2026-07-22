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

int startloop(Node* head){
    Node* slow=head;
    Node* fast=head;
    bool loop=0;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            loop=1;
            break;
        }
    }
    if(loop==0)
        return -1;
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;
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

    Node *g=new Node(2);
    Node *h=new Node(3);
    Node *i=new Node(20);
    g->next=h;
    h->next=i;
    Node* B=g;

    cout<<startloop(A)<<" "<<startloop(B)<<endl;
}