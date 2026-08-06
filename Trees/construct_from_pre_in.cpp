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

int idx=0;  // to track the element of preorder
Node* construct(unordered_map<int,int> &mp,vector<int> &pre,vector<int> &in,int s,int e){
    if(s>e)
        return NULL;
    int element=pre[idx];
    idx++;
    // ++ se point to next element and static h toh value persist between calls
    // make node
    Node* newnode=new Node(element);
    // find position in inorder by map
    int position=mp[element];
    if(s==e)     // becz position-1 and position+1 se next calls main vo return null krega
        return newnode;  // to reduce time
    newnode->left=construct(mp,pre,in,s,position-1);
    newnode->right=construct(mp,pre,in,position+1,e);
    return newnode;
}

Node* build(vector<int> &pre,vector<int> &in){
    idx=0;
    unordered_map<int,int> mp; // ele:index
    // inorder ko baar search na krna pade to find the element of preorder
    // start and end hume search space batayega inorder main
    for(int i=0;i<in.size();i++)
        mp[in[i]]=i;
    Node* root=construct(mp,pre,in,0,in.size()-1);
    return root;
}

int main(){
    vector<int> pre={1,2,4,5,3,6,7};
    vector<int> in={4,2,5,1,6,3,7};
    Node* root=build(pre,in);
    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder : ";
    inorder(root);
}