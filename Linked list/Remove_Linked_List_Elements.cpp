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

Node* removeElements(Node* head,int val){
    // remove leading nodes have values val
    while(head && head->data==val)
        head=head->next;
    if(head==NULL)
        return head;
    Node* prev=head;
    Node* curr=head->next;
    while(curr){
        if(curr->data==val){
            // remove krna h
            prev->next=curr->next;
            curr=prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(6);
    Node *d=new Node(3);
    Node *e=new Node(4);
    Node *f=new Node(5);
    Node *g=new Node(6);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    printLLI(a);
    a=removeElements(a,6);   
    printLLI(a);
}