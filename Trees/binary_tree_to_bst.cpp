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

void preorder(Node* root,vector<int> &ans){
    if(root==NULL)
        return;
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}

void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void inorder_fill(Node* root,vector<int> &ans,int &index){
    if(root==NULL)
        return;
    inorder_fill(root->left,ans,index);
    root->data=ans[index];
    index++;
    inorder_fill(root->right,ans,index);
}

void convert(Node* root){
    vector<int> ans;
    preorder(root,ans);
    sort(ans.begin(),ans.end());
    int index=0;
    inorder_fill(root,ans,index);
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
    inorder(root);
    convert(root);
    cout<<endl;
    inorder(root);
}