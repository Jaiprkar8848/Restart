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

void printLL(Node* head){
    Node* ptr=head;
    while(ptr->next!=head){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data;
    cout<<endl;
}

pair<Node*,Node*> splitHalve(Node* head){
    Node* slow=head;
    Node* fast=head;
    // even nodes ke case main left middle pe rukege kyoki usse hi todna h hume
    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newhead=slow->next;  //  head of second half;
    slow->next=head;   // ban gya first half
    Node* temp=newhead;
    while(temp->next!=head)
        temp=temp->next;
    temp->next=newhead;
    return make_pair(head,newhead);
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
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=a;
    Node* A=a;
    printLL(A);
    pair<Node*,Node*> p=splitHalve(A);
    printLL(p.first);
    printLL(p.second);
}