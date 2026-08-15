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

void inorders(Node* root,vector<int> &in){
    if(root==NULL)
        return;
    inorders(root->left,in);
    in.push_back(root->data);
    inorders(root->right,in);
}

Node* helper(vector<int> &in,int s,int e){
    if(s>e)
        return NULL;
    int mid=s+(e-s)/2;
    Node* temp=new Node(in[mid]);
    temp->left=helper(in,s,mid-1);
    temp->right=helper(in,mid+1,e);
    return temp;
}

Node* balancedBst(Node* root){
    vector<int> in;
    inorders(root,in);
    root=helper(in,0,in.size()-1);
    return root;
}

int main(){
    Node* a=new Node(4);
    Node* b=new Node(3);
    Node* c=new Node(2);
    Node* d=new Node(1);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    a->left=b;
    b->left=c;
    c->left=d;
    a->right=e;
    e->right=f;
    f->right=g;
    Node* root=a;
    root=balancedBst(root);
    inorder(root);
}