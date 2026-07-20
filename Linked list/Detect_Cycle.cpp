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

bool loop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return 1;
    }
    return 0;
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

    cout<<loop(A)<<" "<<loop(B)<<endl;
}