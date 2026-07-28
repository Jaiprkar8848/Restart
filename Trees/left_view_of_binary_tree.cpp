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

vector<int> leftView(Node* root){
    vector<int> v;
    if(root==NULL)
        return v;
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        // no. of nodes at current level
        int cnt=q.size();
        for(int i=1;i<=cnt;i++){
            Node* temp=q.front();
            q.pop();
            if(i==1){
                // har level ka first element in ans
                v.push_back(temp->data);
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return v;
}

int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    // Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    a->left=b;
    a->right=c;
    // b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    Node* root=a;
    vector<int> left=leftView(root);
    for(auto it:left)
        cout<<it<<" ";
}