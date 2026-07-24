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

Node* doubleNum(Node* head){
    // for final carry
    Node* dummy=new Node(0);
    dummy->next=head;
    Node* curr=dummy;
    while(curr->next){
        if(curr->next->data>=5){
            // means carry aayegi
            curr->data=(curr->data*2)%10;
            ++curr->data;
        }
        else    
            curr->data=(curr->data*2)%10;
        curr=curr->next;
    }
    // for the last node
    curr->data=(curr->data*2)%10;
    head=dummy->data==1?dummy:dummy->next;
    return head;
}

int main(){
    Node *a=new Node(9);
    Node *b=new Node(9);
    Node *c=new Node(9);
    a->next=b;
    b->next=c;
    printLLI(a);
    a=doubleNum(a);
    printLLI(a);
}