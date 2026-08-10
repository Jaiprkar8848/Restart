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



// longest path means height wise -> if height same toh maximum
// every node 2 cheeze -> height and sum
pair<int,int> helper(Node* root){
    if(root==NULL)
        return {0,0};
    pair<int,int> p1=helper(root->left);
    pair<int,int> p2=helper(root->right);
    // p1.first=h1,p1.second=val1,p2.first=h2,p2.second=val2;
    if(p1.first>p2.first)
        return {1+p1.first,p1.second+root->data};
    else if(p2.first>p1.first)
        return {1+p2.first,p2.second+root->data};
    else
        return {1+p1.first,max(p1.second,p2.second)+root->data};
}

int solve(Node* root){
    pair<int,int> p=helper(root);
    return p.second;
}

int main(){
    Node* a=new Node(4);
    Node* b=new Node(2);
    Node* c=new Node(5);
    Node* d=new Node(7);
    Node* e=new Node(1);
    Node* f=new Node(2);
    Node* g=new Node(3);
    Node* h=new Node(6);
    Node* i=new Node(4);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    e->left=h;
    f->right=i;
    Node* root=a;
    cout<<solve(root);
}