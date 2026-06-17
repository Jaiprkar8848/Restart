#include<bits/stdc++.h>
using namespace std;

void reverseInGroups(vector<int> &v,int k){
    int n=v.size();
    for(int i=0;i<n;i+=k){
        int s=i;
        int e=min(i+k-1,n-1);
        while(s<e){
            swap(v[s],v[e]);
            s++,e--;
        }
    }
}

int main(){
    vector<int> v={1,2,3,4,5,6,7,8};
    int k=3;
    reverseInGroups(v,k);
    for(auto it:v)
        cout<<it<<" ";
}