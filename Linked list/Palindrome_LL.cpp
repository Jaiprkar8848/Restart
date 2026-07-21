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

bool palindrome(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* a=head;
    Node* b=reverseLL(slow);   // second half reversed
    while(a && b){
        if(a->data!=b->data)
            return 0;
        a=a->next;
        b=b->next;
    }
    return 1;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(2);
    Node *e=new Node(1);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    printLLI(a);
    cout<<palindrome(a);
}