#include<bits/stdc++.h>
using namespace std;

void sortnop(vector<int> &v){
    int n=v.size();
    int l=0,m=0,h=n-1;
    while(m<=h){
        if(v[m]<0)
            swap(v[m++],v[l++]);
        else if(v[m]==0)
            m++;
        else
            swap(v[m],v[h--]);
    }
}

int main(){
    vector<int> v={-5, 0, 12, -3, 0, 7, -8, 0, 15, 2, -1, 0, 9, -6, 0};
    sortnop(v);
    for(auto it:v)
        cout<<it<<" ";
}