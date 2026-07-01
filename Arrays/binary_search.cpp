#include<bits/stdc++.h>
using namespace std;

int searchBinary(vector<int> &v,int target){
    int n=v.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(target==v[mid])
            return mid;
        else if(target<v[mid])
            high=mid-1;
        else    
            low=mid+1;
    }
    return -1;
}

int main(){
    vector<int> v={10,20,30,40,50,60,70,80,90,100};
    cout<<searchBinary(v,30)<<endl;
    cout<<searchBinary(v,70)<<endl;
    cout<<searchBinary(v,1000);
}