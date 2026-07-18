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

void printLLRevR(Node *head){
    if(head==NULL){
        return;
    }
    printLLRevR(head->next);
    cout<<head->data<<" ";
}

void printLLRevI(Node *head){
    stack<Node*> s;
    Node *temp=head;
    while(temp!=NULL){
        s.push(temp);
        temp=temp->next;
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
    cout<<endl;
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
    printLLRevI(a);   
    printLLRevR(a);
}