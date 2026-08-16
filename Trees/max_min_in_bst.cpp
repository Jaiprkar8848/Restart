#include<bits/stdc++.h>
using namespace std;

// way 1 -> inorder nikalke first and last -> in every case order of nodes 
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

// jo node ki value minimum hogi uska left child nhi hoga
int findMin(Node* root){
    if(root==NULL)
        return -1;
    if(root->left==NULL)
        return root->data;
    else
        return findMin(root->left);
}

// max value wali node ka right child NULL hoga
int findMax(Node* root){
    if(root==NULL)
        return -1;
    if(root->right==NULL) 
        return root->data;
    else
        return findMax(root->right);
}

int main(){
    Node* a=new Node(4);
    Node* b=new Node(2);
    Node* c=new Node(6);
    Node* d=new Node(1);
    Node* e=new Node(3);
    Node* f=new Node(5);
    Node* g=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    Node* root=a;
    cout<<findMin(root)<<" "<<findMax(root);
}