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

int ans=INT_MIN;
// if sab nodes +ve -> sum is sum of all values
int helper(Node* root){
    if(root==NULL)
        return 0;
    int lst=helper(root->left);
    int rst=helper(root->right);
    ans=max(ans,lst+rst+root->data);
    return lst+rst+root->data;
}

int solve(Node* root){
    ans=INT_MIN; // resetting
    helper(root);
    return ans;
}

int main(){
    Node* a=new Node(1);
    Node* b=new Node(-2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(-6);
    Node* g=new Node(2);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    Node* root=a;
    cout<<solve(root);
}