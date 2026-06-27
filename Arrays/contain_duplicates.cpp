#include<bits/stdc++.h>
using namespace std;

bool containDup(vector<int> &nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-1;i++){
        if(nums[i]==nums[i+1]) return true;
    }
    return false;
}

int main(){
    vector<int> a={1,1,1,3,3,4,3,2,4,2};
    vector<int> b={1,2,3,4};
    cout<<containDup(a)<<" "<<containDup(b);
}