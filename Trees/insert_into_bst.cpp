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

void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* insert(Node* root,int key){
    // empty tree
    if(root==NULL){
        Node* newnode=new Node(key);
        return newnode;
    }
    if(key<=root->data){
        // key will go into left
        root->left=insert(root->left,key);
    }
    else{
        // key will go into right
        root->right=insert(root->right,key);
    }
    return root;
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
    inorder(root);
    cout<<endl;
    insert(root,8);
    inorder(root);
    cout<<endl;
    insert(root,0);
    inorder(root);
}