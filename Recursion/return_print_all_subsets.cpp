#include<iostream>
#include<vector>
using namespace std;

void powerSet1(int i,int n,vector<int> arr,vector<int> curr,vector<vector<int>> &ans){
    if(i==n){
        ans.push_back(curr);
        return;
    }
    // leave it
    powerSet1(i+1,n,arr,curr,ans);
    curr.push_back(arr[i]);
    powerSet1(i+1,n,arr,curr,ans);
}

void powerSet2(int i,int n,vector<int> arr,vector<int> &curr,vector<vector<int>> &ans){
    if(i==n){
        ans.push_back(curr);
        return;
    }
    // take it
    curr.push_back(arr[i]);
    powerSet2(i+1,n,arr,curr,ans);
    curr.pop_back();   // backtrack
    powerSet2(i+1,n,arr,curr,ans);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> curr;
    vector<vector<int>> ans;
    powerSet2(0,n,arr,curr,ans);
    for(auto vec:ans){
        for(auto ele:vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}