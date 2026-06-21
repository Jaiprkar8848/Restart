#include<bits/stdc++.h>
using namespace std;

void wave(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i+=2)
        swap(v[i],v[i+1]);
}

int main(){
    vector<int> a={1,2,3,4,5};
    vector<int> b={1,2,3,4,5,6};
    wave(a);
    wave(b);
    for(auto it:a)
        cout<<it<<" ";
    cout<<endl;
    for(auto it:b)
        cout<<it<<" ";
}