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


void postorder(Node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int idx=0;  // to track the element of preorder
Node* construct(unordered_map<int,int> &mp,vector<int> &in,vector<int> &post,int s,int e){
    if(s>e)
        return NULL;
    int element=post[idx];
    idx--;
    // ++ se point to next element and static h toh value persist between calls
    // make node
    Node* newnode=new Node(element);
    // find position in inorder by map
    int position=mp[element];
    if(s==e)     // becz position-1 and position+1 se next calls main vo return null krega
        return newnode;  // to reduce time
    newnode->right=construct(mp,in,post,position+1,e);
    newnode->left=construct(mp,in,post,s,position-1);
    return newnode;
}

Node* build(vector<int> &in,vector<int> &post){
    int n=in.size();
    idx=n-1;   // becz post main root end main hota h
    unordered_map<int,int> mp; // ele:idx
    // inorder ko baar search na krna pade to find the element of preorder
    // start and end hume search space batayega inorder main
    for(int i=0;i<in.size();i++)
        mp[in[i]]=i;
    Node* root=construct(mp,in,post,0,in.size()-1);
    return root;
}

int main(){
    vector<int> post={4,5,2,6,7,3,1};
    vector<int> in={4,2,5,1,6,3,7};
    Node* root=build(in,post);
    cout<<"Postorder : ";
    postorder(root);
    cout<<endl;
    cout<<"Inorder : ";
    inorder(root);
}