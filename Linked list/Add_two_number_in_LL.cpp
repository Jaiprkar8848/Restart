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
    Node *agle;
    while(curr){
        agle=curr->next;
        curr->next=prev;
        prev=curr;
        curr=agle;
    }
    return prev;
}

Node* addtwo(Node *head1,Node *head2){
    Node *a=reverseLL(head1);
    Node *b=reverseLL(head2);
    int sum,carry=0;
    Node* result=new Node(0);
    Node* temp=result;
    while(a && b){
        sum=a->data+b->data+carry;
        Node* newnode=new Node(sum%10);
        carry=sum/10;
        temp->next=newnode;
        temp=temp->next;
        a=a->next;
        b=b->next;
    }
    while(a){
        sum=a->data+carry;
        Node* newnode=new Node(sum%10);
        carry=sum/10;
        temp->next=newnode;
        temp=temp->next;
        a=a->next;
    }
    while(b){
        sum=b->data+carry;
        Node* newnode=new Node(sum%10);
        carry=sum/10;
        temp->next=newnode;
        temp=temp->next;
        b=b->next;
    }
    if(carry>0){
        Node* newnode=new Node(carry);
        temp->next=newnode;
        temp=temp->next;
    }
    result=reverseLL(result->next);
    // avoid leading zeros
    while(result && result->data==0)
        result=result->next;
    if(result==NULL)
        return new Node(0);
    return result;
}

int main(){
    Node *a=new Node(0);
    Node *b=new Node(0);
    Node *c=new Node(6);
    Node *d=new Node(3);
    a->next=b;
    b->next=c;
    c->next=d;
    printLLI(a);
    
    Node *e=new Node(0);
    Node *f=new Node(7);
    e->next=f;
    printLLI(e);

    Node* res=addtwo(a,e);
    printLLI(res);
}

/*
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *a=l1;
    ListNode *b=l2;
    ListNode *dummy=new ListNode(-1);
    ListNode *temp=dummy;
    int sum,carry=0;
    while(a || b){
        int x=a?a->val:0;
        int y=b?b->val:0;
        sum=x+y+carry;
        temp->next=new ListNode(sum%10);
        carry=sum/10;
        temp=temp->next;
        if(a) a=a->next;
        if(b) b=b->next;
    }
    if(carry>0)
        temp->next=new ListNode(carry);
    return dummy->next;
}
*/