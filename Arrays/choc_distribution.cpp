#include<bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int> v,int m){
    int n=v.size();
    sort(v.begin(),v.end());
    if(n==m){
        // all pkts distributed
        return v[n-1]-v[0];
    }
    int ans=INT_MAX;
    // checking window of size m
    for(int i=0;i+m-1<n;i++){
        ans=min(ans,v[i+m-1]-v[i]);
    }
    return ans;
}

int main(){
    vector<int> v={3, 4, 1, 9, 56, 7, 9, 12};
    int m=5;
    cout<<findMinDiff(v,m);
}