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
    // iterative approach
    Node* ptr=head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

Node* merge2(Node* a,Node* b){
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            temp->next=a;
            a=a->next;
        }
        else{
            temp->next=b;
            b=b->next;
        }
        temp=temp->next;
    }
    if(a==NULL)
        temp->next=b;
    if(b==NULL)
        temp->next=a;
    
    return dummy->next;
}

// without extra node
Node* merge21(Node* a,Node* b){
    Node* newnode;
    if(a->data<b->data){
        newnode=a;
        a=a->next;
    }
    else{
        newnode=b;
        b=b->next;
    }
    Node* temp=newnode;
    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            temp->next=a;
            a=a->next;
        }
        else{
            temp->next=b;
            b=b->next;
        }
        temp=temp->next;
    }
    if(a==NULL)
        temp->next=b;
    if(b==NULL)
        temp->next=a;
    
    return newnode;
}

int main(){
    Node *a=new Node(5);
    Node *b=new Node(10);
    Node *c=new Node(15);
    Node *d=new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    Node* A=a;

    Node *g=new Node(2);
    Node *h=new Node(3);
    Node *i=new Node(20);
    g->next=h;
    h->next=i;
    Node* B=g;

    printLL(A);
    printLL(B);
    Node* C=merge21(A,B);
    printLL(C);
}