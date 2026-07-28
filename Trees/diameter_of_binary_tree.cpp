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

int helper(Node* root,int &diam){
    if(root==NULL)
        return 0;
    int lheight=helper(root->left,diam);
    int rheight=helper(root->right,diam);
    diam=max(lheight+rheight,diam);
    // height of current node
    return 1+max(lheight,rheight);
}

int diameter(Node* root){
    int diam=0;
    helper(root,diam);
    return diam;
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
    cout<<diameter(root);
}