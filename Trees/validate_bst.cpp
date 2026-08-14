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

// inorder sorted hota h bst ka
void inorder(Node* root,vector<int> &ans){
    if(root==NULL)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

bool way1(Node* root){
    vector<int> ans;
    inorder(root,ans);
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i]>ans[i+1])
            return 0;
    }
    return 1;
}

// lst range (left_range to root->val-1)
// rst range (right_range to root->val+1)
bool helper(Node* root,int mini,int maxi){
    if(root==NULL)
        return 1;
    if(root->data<mini || root->data>maxi)
        return 0;    
    bool lst=helper(root->left,mini,root->data-1);
    bool rst=helper(root->right,root->data+1,maxi);
    return lst && rst;
}

bool way2(Node* root){
    int mini=INT_MIN;
    int maxi=INT_MAX;
    return helper(root,mini,maxi);
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
    cout<<way1(root)<<" "<<way2(root);
}