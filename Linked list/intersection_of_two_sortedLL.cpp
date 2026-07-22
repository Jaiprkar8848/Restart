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

Node* intersection(Node* a,Node *b){
    Node* dummy=new Node(-1);
    Node* last=dummy;
    while(a && b){
        if(a->data==b->data){
            // create a new node
            Node* temp=new Node(a->data);
            last->next=temp;
            a=a->next;
            b=b->next;
            last=last->next;
        }
        else if(a->data<b->data){
            // ye ho skta h a main aage kuch node ho jo b wale ke barabar ho
            a=a->next;
        }
        else{
            b=b->next;
        }
    }
    return dummy->next;
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
    Node *h=new Node(10);
    Node *i=new Node(15);
    Node *j=new Node(20);
    g->next=h;
    h->next=i;
    i->next=j;
    Node* B=g;

    printLL(A);
    printLL(B);
    Node* C=intersection(A,B);
    printLL(C);
}