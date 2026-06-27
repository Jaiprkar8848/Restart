#include<bits/stdc++.h>
using namespace std;
/*
Brute -> for every element find product of remaining 
*/

vector<int> prodEx(vector<int> &v){
    int n=v.size();
    vector<int> preProd(n,v[0]);
    for(int i=1;i<n;i++)
        preProd[i]=preProd[i-1]*v[i];
    vector<int> sufProd(n,v[n-1]);
    for(int i=n-2;i>=0;i--)
        sufProd[i]=sufProd[i+1]*v[i];
    vector<int> ans(n,0);
    ans[0]=sufProd[1];
    ans[n-1]=preProd[n-2];
    for(int i=1;i<n-1;i++){
        ans[i]=preProd[i-1]*sufProd[i+1];
    }
    return ans;
}

int main(){
    vector<int> v={1,2,3,4,5};
    vector<int> ans=prodEx(v);   
    for(auto it:ans)
        cout<<it<<" ";
}