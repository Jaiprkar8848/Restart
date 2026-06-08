#include<bits/stdc++.h>
using namespace std;

void f(int idx,int target,vector<int> &arr,vector<int> &curr,vector<vector<int>> &ans){
    if(idx==arr.size()){
        if(target==0)
            ans.push_back(curr);
        return;
    }
    // pick
    if(arr[idx]<=target){
        curr.push_back(arr[idx]);
        f(idx,target-arr[idx],arr,curr,ans);
        curr.pop_back();
    }
    // not pick
    f(idx+1,target,arr,curr,ans);
}

vector<vector<int>> combSum(vector<int> &arr,int target){
    vector<vector<int>> ans;
    vector<int> curr;
    f(0,target,arr,curr,ans);
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<vector<int>> ans=combSum(arr,target);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}