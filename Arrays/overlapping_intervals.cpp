#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge_intervals(vector<vector<int>> &v){
    int n=v.size();
    vector<vector<int>> ans;
    sort(v.begin(),v.end());
    ans.push_back(v[0]);
    for(int i=1;i<n;i++){
        int s1=ans.back()[0];
        int e1=ans.back()[1];
        int s2=v[i][0];
        int e2=v[i][1];
        if(s2<=e1){
            // overlap
            ans.back()[1]=max(e1,e2);
        }
        else
            ans.push_back(v[i]);
    }
    return ans;
}

int main(){
    vector<vector<int>> v={{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    vector<vector<int>> overlapped=merge_intervals(v);
    for(auto it:overlapped)
        cout<<"["<<it[0]<<","<<it[1]<<"]"<<endl;   
}