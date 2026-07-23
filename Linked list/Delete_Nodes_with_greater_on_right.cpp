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

void printLLI(Node* head){
    // iterative approach
    Node* ptr=head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

Node* reverseLL(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* agle;
    while(curr){
        agle=curr->next;
        curr->next=prev;
        prev=curr;
        curr=agle;
    }
    return prev;
}

Node* deleteNodes(Node* head){
    head=reverseLL(head);
    Node* prev=NULL;
    Node* curr=head;
    Node* agle;
    int maxi=INT_MIN;
    while(curr){
        agle=curr->next;
        if(curr->data>=maxi){
            // part of resultant LL
            maxi=curr->data;
            curr->next=prev;
            prev=curr;
        }
        curr=agle;
    }
    return prev;
}

int main(){
    Node *a=new Node(12);
    Node *b=new Node(15);
    Node *c=new Node(10);
    Node *d=new Node(11);
    Node *e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(2);
    Node* h=new Node(3);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=h;
    printLLI(a);
    a=deleteNodes(a);
    printLLI(a);
}