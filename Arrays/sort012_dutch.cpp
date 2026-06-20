#include<bits/stdc++.h>
using namespace std;
/*
00001111????2222
0 -> 0 to low-1
1 -> low+1 to mid-1
2 -> high+1 to n-1
? wale part ko hume fix krna h
mid to high tk h ????
*/

void sort012(vector<int> &v){
    int n=v.size();
    int l=0,m=0,h=n-1;
    while(m<=h){
        if(v[m]==0)
            swap(v[m++],v[l++]);
        else if(v[m]==1)
            m++;
        else
            swap(v[m],v[h--]);
    }
}

int main(){
    vector<int> v={0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    sort012(v);
    for(auto it:v)
        cout<<it<<" ";
}