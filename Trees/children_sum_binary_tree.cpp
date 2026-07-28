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

bool childrenSum(Node* root){
    if(root==NULL)
        return 1;
    if(root->left==NULL && root->right==NULL)
        return 1;
    int sum=0;
    sum+=(root->left)?(root->left->data):0;
    sum+=(root->right)?(root->right->data):0;
    if(sum!=root->data)
        return 0;
    return childrenSum(root->left) && childrenSum(root->right);
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
    cout<<childrenSum(root);
}