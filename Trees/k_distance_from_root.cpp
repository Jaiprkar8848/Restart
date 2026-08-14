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
// way1 -> level order traversal -> print kth level nodes

void helper(Node* root,int k,vector<int> &ans){
    if(root==NULL)
        return;
    if(k==0){
        ans.push_back(root->data);
        return;
    }
    helper(root->left,k-1,ans);
    helper(root->right,k-1,ans);
}

vector<int> kth(Node* root,int k){
    vector<int> ans;
    helper(root,k,ans);
    return ans;
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
    vector<int> ans=kth(root,2);
    for(auto it:ans)
        cout<<it<<" ";
}