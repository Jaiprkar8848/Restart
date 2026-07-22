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

Node* removeDup(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    unordered_map<int,int> mp;
    while(curr!=NULL){
        if(mp[curr->data]==1){
            // already vo data agya h 
            // means duplicate
            prev->next=curr->next;
            free(curr);
            curr=prev->next;
        }
        else{
            mp[curr->data]=1;
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    Node *a=new Node(5);
    Node *b=new Node(2);
    Node *c=new Node(2);
    Node *d=new Node(3);
    Node *e=new Node(3);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    Node* A=a;
    printLL(A);
    A=removeDup(A);
    printLL(A);
}