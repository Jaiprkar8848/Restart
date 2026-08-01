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

vector<int> diagonal(Node* root){
    vector<int> v;
    if(root==NULL)
        return v;
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        // pop the current
        Node* curr=q.front();
        q.pop();
        while(curr){
            // becz of tracking diagonal change
            if(curr->left)
                q.push(curr->left);
            v.push_back(curr->data);
            curr=curr->right;
        }
    }
    return v;
}

int main(){
    Node* a=new Node(8);
    Node* b=new Node(3);
    Node* c=new Node(10);
    Node* d=new Node(1);
    Node* e=new Node(6);
    Node* g=new Node(14);
    Node* j=new Node(4);
    Node* k=new Node(7);
    Node* l=new Node(13);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=g;
    e->left=j;
    e->right=k;
    g->left=l;
    Node* root=a;
    vector<int> v=diagonal(root);
    for(auto it:v)
        cout<<it<<" ";
}