#include<bits/stdc++.h>
using namespace std;

int majority(vector<int> &v){
    sort(v.begin(),v.end());
    return v[v.size()/2];
}

int main(){
    vector<int> v={1, 1, 2, 1, 3, 5, 1};
    cout<<majority(v);
}