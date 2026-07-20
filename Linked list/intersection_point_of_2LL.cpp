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
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int countNodes(Node* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

Node* intersection(Node* a,Node* b){
    int m=countNodes(a);
    int n=countNodes(b);
    int diff=abs(m-n);
    if(m>n){
        // first head wali list lambi h
        // toh uske head ko diff se aage badhao
        while(diff>0){
            a=a->next;
            diff--;
        }
    }
    else{
        // second head wali list lambi h
        // toh uske head ko diff se aage badhao
        while(diff>0){
            b=b->next;
            diff--;
        }
    }
    while(a!=NULL && b!=NULL){
        // jb tk dono main se ek end nhi ho jati
        if(a==b)
            return a;
        a=a->next;
        b=b->next;
    }

    // agar ek bhi end hogyi
    // means no intersection point
    return NULL;
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

    Node* g=new Node(6);
    g->next=d;

    Node* intersection_node=intersection(a,g);
    printLL(intersection_node);
}