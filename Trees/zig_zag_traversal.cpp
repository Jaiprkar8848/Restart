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

vector<int> zig_zag(Node* root){
    vector<int> v;
    if(root==NULL)
        return v;
    queue<Node*> q;
    q.push(root);
    vector<int> temp;
    bool flag=1; // check for level odd or even
    while(q.size()>0){
        temp.clear();
        int cnt=q.size();
        for(int i=1;i<=cnt;i++){
            Node* curr=q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        if(flag==0)   // level change
            reverse(temp.begin(),temp.end());
        flag=!flag;
        for(auto it:temp)
            v.push_back(it);
    }
    return v;
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
    vector<int> v=zig_zag(root);
    for(auto it:v)
        cout<<it<<" ";
}