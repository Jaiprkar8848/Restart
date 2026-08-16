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
Node* findLCA(Node* root,Node* p,Node* q){
    if(root==NULL)
        return root;
    if(root->data==p->data || root->data==q->data)
        return root;
    // 3 case -> both are in other side // left side // right side
    Node* lefty=findLCA(root->left,p,q);
    Node* righty=findLCA(root->right,p,q);
    if(lefty && righty)
        return root;
    else if(lefty)
        return lefty;
    else
        return righty;
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
    cout<<findLCA(root,b,f)->data;
}