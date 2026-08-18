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

// way1 -> inorder nikalke search kro just smaller and just greater wala hamara answer hoga
// Order of nodes

void findPred(Node* root,Node* &pred,int key){
    if(root==NULL)
        return;
    if(root->data<key){
        pred=root;
        findPred(root->right,pred,key);
    }
    else
        findPred(root->left,pred,key);
}

void findSucc(Node* root,Node* &succ,int key){
    if(root==NULL)
        return;
    if(root->data>key){
        succ=root;
        findSucc(root->left,succ,key);
    }
    else
        findSucc(root->right,succ,key);
}

vector<Node*> findPredSucc(Node* root,int key){
    Node* pred=NULL;
    Node* succ=NULL;
    vector<Node*> ans;
    findPred(root,pred,key);
    findSucc(root,succ,key);
    ans.push_back(pred);
    ans.push_back(succ);
    return ans;
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
    vector<Node*> ans=findPredSucc(root,5);
    cout<<ans[0]->data<<" "<<ans[1]->data;
}