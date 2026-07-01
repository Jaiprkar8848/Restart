#include<bits/stdc++.h>
using namespace std;
/*
Brute for each subarray maintain set
O(n*k)
*/
vector<int> countDistinct(vector<int> &v,int k){
    int n=v.size();
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<k;i++)
        mp[v[i]]+=1;
    ans.push_back(mp.size());
    // sliding through endpoint
    for(int i=k;i<n;i++){
        int add_index=i;
        int remove_index=i-k;
        if(mp.find(v[remove_index])!=mp.end()){
            // means that element freq is there
            mp[v[remove_index]]-=1;
            if(mp[v[remove_index]]==0)
                mp.erase(v[remove_index]);
        }
        mp[v[add_index]]+=1;
        ans.push_back(mp.size());
    }
    return ans;
}

int main(){
    vector<int> v={1, 2, 1, 3, 4, 2, 3};
    int k=4;
    vector<int> ans=countDistinct(v,k);
    for(auto it:ans)
        cout<<it<<" ";
}