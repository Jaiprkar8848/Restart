#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v={5, 7, 2, 7, 5, 2, 5};
    int ans=0;
    for(int i=0;i<v.size();i++)
        ans=ans^v[i];
    cout<<ans;
}