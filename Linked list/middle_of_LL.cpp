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

int middle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}

int firstMiddle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL  && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    // Node *e=new Node(5);
    a->next=b;
    b->next=c;
    c->next=d;
    // d->next=e;
    cout<<middle(a)<<" "<<firstMiddle(a);
}