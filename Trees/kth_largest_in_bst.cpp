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

void helper(Node* root,vector<int> &ans){
    if(root==NULL)
        return;
    helper(root->right,ans);
    ans.push_back(root->data);
    helper(root->left,ans);
}

int kthLargest(Node* root,int k){
    vector<int> ans;
    helper(root,ans);
    if(k>ans.size())
        return -1;
    return ans[k-1];
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
    cout<<kthLargest(root,5);
}