#include<bits/stdc++.h>
using namespace std;

int missing(vector<int> &v){
    int n=v.size();
    int hona_chahiye=n*(n+1)/2;
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=v[i];
    return hona_chahiye-sum;
}

int main(){
    vector<int> v={9,6,4,2,3,5,7,0,1};
    cout<<missing(v);
}