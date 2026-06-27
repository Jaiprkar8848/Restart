#include<bits/stdc++.h>
using namespace std;

/*
Brute force -> find all perm, sort them lexicographically, find answer
*/

void nextPerm(vector<int> &v){
    int n=v.size();
    int breakPoint=-1;    // index from right which have greater number to its adjacent right
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            breakPoint=i;
            break;
        }
    } 
    if(breakPoint==-1){
        // last permutation h
        reverse(v.begin(),v.end());
        return;
    }
    // find just greater element -> swap it
    for(int j=n-1;j>breakPoint;j--){
        if(v[j]>v[breakPoint]){
            swap(v[j],v[breakPoint]);
            break;
        }
    }
    // reverse after bp
    reverse(v.begin()+breakPoint+1,v.end());
}

int main(){
    vector<int> a={1,3,5,4,2};
    vector<int> b={4,7,8,2,1,9};
    nextPerm(a);
    nextPerm(b);
    for(auto it:a)
        cout<<it<<" ";
    cout<<endl;
    for(auto it:b)
        cout<<it<<" ";
}