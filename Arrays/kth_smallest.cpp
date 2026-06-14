#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &v,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto it:v)
        pq.push(it);
    k-=1;
    while(k--)
        pq.pop();
    return pq.top();
}

int main(){
    vector<int> v={10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k=4;
    cout<<kthSmallest(v,k);
}