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


int helper(Node* root){
    if(root==NULL)
        return 0;  // parent ko kya bhejega
    int x=root->data;      // save ki becz ye update hogi -> old value ko save krliya
    int lst=helper(root->left);  // left subtree ka sum
    int rst=helper(root->right);
    root->data=lst+rst;
    return lst+rst+x;
}

void transform(Node* root){
    helper(root);
}

void preorder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* a=new Node(10);
    Node* b=new Node(-2);
    Node* c=new Node(6);
    Node* d=new Node(8);
    Node* e=new Node(-4);
    Node* f=new Node(7);
    Node* g=new Node(5);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    Node* root=a;
    transform(root);
    preorder(root);
}