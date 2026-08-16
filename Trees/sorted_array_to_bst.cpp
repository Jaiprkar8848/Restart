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

void preorder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node* helper(vector<int> &v,int s,int e){
    if(s>e)
        return NULL;
    int mid=s+(e-s)/2;
    Node* root=new Node(v[mid]);
    root->left=helper(v,s,mid-1);
    root->right=helper(v,mid+1,e);
    return root;
}

Node* construct(vector<int> &v){
    return helper(v,0,v.size()-1);
}

int main(){
    vector<int> v={1,2,3,4,5,6,7,8};
    Node* root=construct(v);
    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder : ";
    postorder(root);
}