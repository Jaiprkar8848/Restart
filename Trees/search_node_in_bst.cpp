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

Node* searchBst(Node* root,int key){
    if(root==NULL)
        return root;
    // go towards left
    if(root->data==key)
        return root;
    else if(root->data>key)
        return searchBst(root->left,key);
    else 
        return searchBst(root->right,key);
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
    if(searchBst(root,6))
        cout<<"6 is present\n";
    if(searchBst(root,14)==NULL)
        cout<<"14 not found"; 
}