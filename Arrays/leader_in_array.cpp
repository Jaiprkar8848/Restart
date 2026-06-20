#include<bits/stdc++.h>
using namespace std;

vector<int> way1(vector<int> &v){
    int n=v.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        int j;
        for(j=i+1;j<n;j++){
            if(v[i]<v[j]) break;
        }
        if(j==n) ans.push_back(v[i]);
    }
    return ans;
}

vector<int> way2(vector<int> &v){
    int n=v.size();
    vector<int> ans;
    int max_from_right=v[n-1];
    ans.push_back(max_from_right);
    for(int i=n-2;i>=0;i--){
        if(v[i]>=max_from_right){
            ans.push_back(v[i]);
            max_from_right=v[i];
        }
    }
    return ans;
}

int main(){
    vector<int> v={16, 17, 4, 3, 5, 2};
    vector<int> ans1=way1(v);
    for(auto it:ans1)
        cout<<it<<" ";
    cout<<endl;
    vector<int> ans2=way2(v);
    for(auto it:ans2)
        cout<<it<<" ";
}