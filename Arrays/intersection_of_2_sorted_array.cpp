#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &a,vector<int> &b){
    int m=a.size(),n=b.size();
    int i=0,j=0;
    vector<int> ans;
    while(i<m && j<n){
        while(i>0 && i<m && a[i]==a[i-1]) i++;
        while(j>0 && j<n && b[j]==b[j-1]) j++;
        if(i>=m || j>=n) break;
        if(a[i]==b[j]){
            ans.push_back(a[i]);
            i++,j++;
        }
        else if(a[i]<b[j]) i++;
        else j++;
    }
    return ans;
}

int main(){
    vector<int> a={1, 2, 2, 3, 4};
    vector<int> b={2, 2, 4, 6, 7, 8};
    vector<int> ans=intersection(a,b);
    for(auto it:ans)
        cout<<it<<" ";
}