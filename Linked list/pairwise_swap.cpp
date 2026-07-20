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

Node* pairwise1(Node* head){
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        swap(temp->data,temp->next->data);
        temp=temp->next->next;
    }
    return head;
}

Node* pairwise2(Node* head){
    if(head==NULL || head->next==NULL)
        return head;
    Node* first=head;
    Node* second=head->next;
    while(second && second->next){
        swap(first->data,second->data);
        first=first->next->next;
        second=second->next->next;
    }
    if(second!=NULL)
        swap(first->data,second->data);
    return head;
}

Node* pairwise3(Node* head){
    Node *prev=NULL,*agla=NULL;
    Node* curr=head,*temp;
    Node* newnode=head->next;
    while(curr && curr->next){
        agla=curr->next;
        temp=agla->next;
        agla->next=curr;
        curr->next=temp;
        if(prev){
            prev->next=agla;
        }
        prev=curr;
        curr=temp;
    }
    return newnode;
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
    printLL(a);
    Node* head=pairwise3(a);
    printLL(head);
    head=pairwise2(head);
    printLL(head);
    head=pairwise1(head);
    printLL(head);
}