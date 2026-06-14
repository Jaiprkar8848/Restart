#include<bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> &v,int k){
    priority_queue<int> pq;
    for(auto it:v)
        pq.push(it);
    k-=1;
    while(k--)
        pq.pop();
    return pq.top();
}

int main(){
    vector<int> v={3,2,3,1,2,4,5,5,6};
    int k=4;
    cout<<kthLargest(v,k);
}