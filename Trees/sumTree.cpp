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

bool flag=1; // we assume tree is sum tree initially

int sumbhejo(Node* root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    int leftsum=sumbhejo(root->left);
    int rightsum=sumbhejo(root->right);
    if(leftsum+rightsum!=root->data)
        flag=0;
    return leftsum+rightsum+root->data;
}

bool sumTree(Node* root){
    flag=1; // reset the flag for each call
    sumbhejo(root);
    return flag;
}

int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(10);
    Node* e=new Node(10);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    Node* root=a;
    cout<<sumTree(root);
}