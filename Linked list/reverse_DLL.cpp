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

Node* reverseDLL(Node *head){
    Node *pre=NULL;
    Node *curr=head;
    Node *nxt;
    while(curr){
        nxt=curr->next;
        curr->next=pre;
        curr->prev=nxt;
        pre=curr;
        curr=nxt;
    }
    return pre;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    a->next=b;
    b->next=c;
    b->prev=a;
    c->next=d;
    c->prev=b;
    d->next=e;
    d->prev=c;
    e->prev=d;
    printLLI(a);
    a=reverseDLL(a);
    printLLI(a);
}