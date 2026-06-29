#include<bits/stdc++.h>
using namespace std;

/*
Brute - find lsum and rsum for every idx -> n square*/

int way1(vector<int> &v){
    int n=v.size();
    vector<int> lsum(n,0);
    for(int i=1;i<n;i++)
        lsum[i]=lsum[i-1]+v[i-1];
    vector<int> rsum(n,0);
    for(int i=n-2;i>=0;i--)
        rsum[i]=rsum[i+1]+v[i+1];
    for(int i=0;i<n;i++){
        if(lsum[i]==rsum[i])
            return i;
    }
    return -1;
}

int way2(vector<int> &v){
    // we know that lsum[i]+rsum[i]+arr[i]=sum
    int n=v.size();
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=v[i];
    int lsum=0; // initially
    int rsum;
    for(int i=0;i<n;i++){
        rsum=sum-v[i]-lsum;
        if(lsum==rsum)
            return i;
        lsum=lsum+v[i];
    }
    return -1;
}

int main(){
    vector<int> v={-7, 1, 5, 2, -4, 3, 0};
    cout<<way1(v)<<endl;
    cout<<way2(v)<<endl;
}