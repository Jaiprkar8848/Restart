#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &v){
    int n=v.size();
    vector<int> lmax(n,v[0]);
    for(int i=1;i<n;i++)
        lmax[i]=max(lmax[i-1],v[i]);
    vector<int> rmax(n,v[n-1]);
    for(int i=n-2;i>=0;i--)
        rmax[i]=max(rmax[i+1],v[i]);
    int water=0;
    for(int i=1;i<n-1;i++)
        water+=min(lmax[i],rmax[i])-v[i];
    return water;
}

int main(){
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(v);
}