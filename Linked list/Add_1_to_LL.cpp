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
    while(ptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

Node* reverseLL(Node* head){
    Node *prev,*curr,*agle;
    prev=NULL;
    curr=head;
    while(curr){
        agle=curr->next;
        curr->next=prev;
        prev=curr;
        curr=agle;
    }
    return prev;
}

Node* addOne(Node* head){
    head=reverseLL(head);
    Node* ptr=head;
    while(ptr->next && ptr->data==9){
        ptr->data=0;
        ptr=ptr->next;
    }
    if(ptr->data==9){
        Node* newnode=new Node(1);
        ptr->next=newnode;
        ptr->data=0;
    }
    else
        ptr->data+=1;
    head=reverseLL(head);
    return head;
}

int main(){
    Node *a=new Node(9);
    Node *b=new Node(9);
    Node *c=new Node(9);
    Node *d=new Node(9);
    Node *e=new Node(9);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    Node* A=a;
    printLL(A);
    A=addOne(A);
    printLL(A);
}