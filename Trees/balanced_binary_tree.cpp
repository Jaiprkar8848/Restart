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

int height(Node* root){
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

bool isBalanced(Node* root){
    if(root==NULL)
        return 1;
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    if(leftHeight!=rightHeight)
        return 0;
    // check left sub and right sub
    return isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    Node* root=a;
    cout<<isBalanced(root);
}