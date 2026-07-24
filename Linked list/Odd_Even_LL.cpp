#include<bits/stdc++.h>
using namespace std;
/*Brute force
maintain odd and even somewhere and update ll -> extra space
*/
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

Node* oddEven(Node* head){
    Node* evenS=new Node(0);
    Node* evenE=evenS;
    Node* oddS=new Node(-1);
    Node* oddE=oddS;
    bool flag=1;
    while(head){
        if(flag){
            oddE->next=head;
            oddE=oddE->next;
        }
        else{
            evenE->next=head;
            evenE=evenE->next;
        }
        flag=!flag;
        head=head->next;
    }
    evenE->next=NULL;
    oddE->next=evenS->next;
    head=oddS->next;
    return head;

}
int main(){
    Node *a=new Node(2);
    Node *b=new Node(1);
    Node *c=new Node(3);
    Node *d=new Node(5);
    Node *e=new Node(6);
    Node *f=new Node(4);
    Node *g=new Node(7);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    printLLI(a);
    a=oddEven(a);
    printLLI(a);
}