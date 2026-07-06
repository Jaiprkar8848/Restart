#include<bits/stdc++.h>
using namespace std;

bool exist(vector<int> &v){
    int n=v.size();
    if(v[0]==0) return 0; // kyoki ye hamare aage ke part main count nhi hoga
    for(int i=1;i<n;i++){
        v[i]+=v[i-1];
        if(v[i]==0) return true;     
    }
    unordered_map<int,int> mp;
    for(auto it:v){
        mp[it]++;
        if(mp[it]>1) return true;
    }
    return false;
}

int main(){
    vector<int> v={4, 2, -3, 1, 6};
    if(exist(v))
        cout<<"Yes";
    else
        cout<<"No";
}