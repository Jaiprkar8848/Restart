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

int length(Node* head){
    Node* ptr=head;
    int c=0;
    while(ptr){
        c++;
        ptr=ptr->next;
    }
    return c;
}

int main(){
    Node *a=new Node(5);
    Node *b=new Node(4);
    Node *c=new Node(51);
    Node *d=new Node(54);
    Node *e=new Node(6);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    cout<<length(a);
}