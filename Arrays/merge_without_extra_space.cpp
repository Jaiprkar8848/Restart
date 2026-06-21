#include<bits/stdc++.h>
using namespace std;

void merge_without_space(vector<int> &a,vector<int> &b){
    int m=a.size();
    int n=b.size();
    int i=m-1,j=0;
    while(i>=0 && j<n){
        if(a[i]>b[j]){
            // means a[i] apni shi jagah pe nhi h
            swap(a[i--],b[j++]);
        }
        else
            break;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
}

int main(){
    vector<int> a={1,5,9,10,15,20};
    vector<int> b={2,3,8,13};
    merge_without_space(a,b);
    for(auto it:a)
        cout<<it<<" ";
    for(auto it:b)
        cout<<it<<" ";
}