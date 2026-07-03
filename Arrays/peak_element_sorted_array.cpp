#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n;i++){
        if(v[i]>v[i+1])
            return i;
    }
    // if no peak
    return -1;
}

int way1(vector<int> &v){
    int n=v.size();
    int s=0,e=n-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(v[mid]<v[mid+1]){
            // first half main h hum
            // we can discard till mid becz we are sure ki mid tk ke element main 
            // peak nhi h
            s=mid+1;
        }
        else{
            // either we are on second half
            // or our mid is pointing to peak
            e=mid;
        }
    }
    return s; // return e
}

int way2(vector<int> &v){
    int n=v.size();
    int s=0,e=n-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(v[mid]>v[mid+1]){
            // either we are on second half
            // or mid pointing to peak
            e=mid;
        }
        else
            s=mid+1;
    }
    return s;
}

int main(){
    vector<int> v={1, 2, 4, 5, 7, 8, 3};
    cout<<brute(v)<<" "<<way1(v)<<" "<<way2(v);
}