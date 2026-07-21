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

Node* reverseLLI(Node* head,int k){
    if(head==NULL)
        return head;
    /*
    if u don't want size<k reversed
    int cnt=countNode(Head)
    if(cnt<k)
        return head
    */
    Node* prev=NULL;
    Node* curr=head;
    Node* agle;
    int p=k;
    while(p-->0 && curr){
        agle=curr->next;
        curr->next=prev;
        prev=curr;
        curr=agle;
    }
    Node* temp=prev;
    while(temp->next)
        temp=temp->next;
    temp->next=reverseLLI(agle,k);
    return prev;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    printLLI(a);
    a=reverseLLI(a,2);
    printLLI(a);
    a=reverseLLI(a,3);
    printLLI(a);
}