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

// upar se dekhenge toh aise lenge like root ko base maanke
// left side main level decreases -1 -2 ...
// right side main level increase +1 +2 ...
// har level ka first element
vector<int> topview(Node* root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    unordered_map<int,int> mp; // level:value
    queue<pair<int,Node*>> q;
    q.push({0,root});
    int mini=INT_MAX;  // level start
    int maxi=INT_MIN;  // level end
    while(q.size()>0){
        pair<int,Node*> p=q.front();
        q.pop();
        int level=p.first;
        if(p.second->left)
            q.push({level-1,p.second->left});
        if(p.second->right)
            q.push({level+1,p.second->right});
        if(mp.find(level)==mp.end()) // entry of level is not there in the map
            mp[level]=p.second->data;
        mini=min(mini,level);
        maxi=max(maxi,level);
    }

    for(int i=mini;i<=maxi;i++)
        ans.push_back(mp[i]);
    
    return ans;
}

int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    Node* e=new Node(60);
    Node* f=new Node(90);
    Node* g=new Node(100);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    Node* root=a;
    vector<int> ans=topview(root);
    for(auto it:ans)
        cout<<it<<endl;
}