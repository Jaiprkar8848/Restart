#include<bits/stdc++.h>
using namespace std;
/*
Brute har buy ke liye highest sell dhundna h aage se
Order of n square
*/

int way1(vector<int> &v){
    int n=v.size();
    vector<int> rightMax(n,v[n-1]);
    for(int i=n-2;i>=0;i--)
        rightMax[i]=max(rightMax[i+1],v[i]);
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
        ans=max(ans,rightMax[i]-v[i]);
    return ans;
}


int way2(vector<int> &v){
    int n=v.size();
    int rmax=v[n-1];
    int ans=0;
    for(int i=n-1;i>=0;i--){
        rmax=max(v[i],rmax);
        ans=max(rmax-v[i],ans);
    }
    return ans;
}

int way3(vector<int> &v){
    int lmin=v[0];
    int n=v.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        lmin=min(lmin,v[i]);
        ans=max(v[i]-lmin,ans);        
    }
    return ans;
}

int main(){
    vector<int> v={7,1,5,3,6,4};
    cout<<way1(v)<<endl;
    cout<<way2(v)<<endl;
    cout<<way3(v);
}