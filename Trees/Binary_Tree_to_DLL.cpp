#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x){
            this->data=x;
            this->left=NULL;
            this->right=NULL;
        }
};


Node* prevNode=NULL;   // point krega lst ke end ko everytime connection krne ke liye
Node* head=NULL;   // initially DLL kuch nhi h toh null set

void construct(Node* root){
    if(root==NULL)
        return;
    // apply on left subtree
    construct(root->left);
    if(prevNode==NULL){
        head=root;
    }
    else{
        prevNode->right=root;
        root->left=prevNode;
    }
    prevNode=root;
    // apply on right subtree
    construct(root->right);
}

Node* build(Node* root){
    construct(root);
    return head;    
}

int main(){
    Node* a=new Node(35);
    Node* b=new Node(20);
    Node* c=new Node(15);
    Node* d=new Node(15);
    Node* e=new Node(5);
    Node* f=new Node(10);
    Node* g=new Node(5);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    Node* root=a;
    Node* head=build(root);
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }
}