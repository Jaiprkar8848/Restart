#include<bits/stdc++.h>
using namespace std;

/*
Brute force -> go through all subarray of size k
*/
vector<int> way(vector<int> &v,int k){
    int n=v.size();
    vector<int> ans;
    deque<int> dq;   // track neg element idx
    for(int i=0;i<k;i++){
        if(v[i]<0)
            dq.push_back(i);
    }
    if(dq.size()==0)
        ans.push_back(0);
    else
        ans.push_back(v[dq.front()]);
    // slide window by endpoint
    for(int i=k;i<n;i++){
        int insert_index=i;
        int pop_index=i-k;
        if(v[insert_index]<0)
            dq.push_back(insert_index);
        if(dq.size()!=0 && dq.front()==pop_index)
            dq.pop_front();
        if(dq.size()==0)
            ans.push_back(0);
        else 
            ans.push_back(v[dq.front()]);
    }
    return ans;
}

int main(){
    vector<int> v={12, -1, -7, 8, -15, 30, 16, 28}; // n-k+1 windows/subarrays
    int k=3;
    vector<int> ans=way(v,k);
    for(auto it:ans)
        cout<<it<<" ";
}