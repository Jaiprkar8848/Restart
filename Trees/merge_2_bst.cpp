#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
};

void inorder(Node* r1,vector<int> &v){
    if(r1==NULL)
        return;
    inorder(r1->left,v);
    v.push_back(r1->data);
    inorder(r1->right,v);
}

vector<int> merge(vector<int> &v1,vector<int> &v2){
    int i=0,j=0,k=0;
    int m=v1.size();
    int n=v2.size();
    vector<int> v(m+n,0);
    while(i<m && j<n){
        if(v1[i]<v2[j])
            v[k++]=v1[i++];
        else
            v[k++]=v2[j++];
    }
    while(i<m)
        v[k++]=v1[i++];
    while(j<n)
        v[k++]=v2[j++];
        
    return v;
}

vector<int> mergeBst(Node* r1,Node* r2){
    vector<int> v1;
    inorder(r1,v1);
    vector<int> v2;
    inorder(r2,v2);
    return merge(v1,v2);
}

int main(){
    Node* a=new Node(3);
    Node* b=new Node(1);
    Node* c=new Node(5);
    a->left=b;
    a->right=c;
    Node* r1=a;
    
    Node* d=new Node(4);
    Node* e=new Node(2);
    Node* f=new Node(6);
    d->left=e;
    d->right=f;
    Node* r2=d;

    vector<int> v=mergeBst(r1,r2);
    for(auto it:v)
        cout<<it<<" ";
}