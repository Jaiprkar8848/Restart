#include<bits/stdc++.h>
using namespace std;

int first(vector<int> &v,int x){
    int n=v.size();
    int s=0,e=n-1,ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]==x){
            ans=mid;
            e=mid-1;
        }
        else if(x<v[mid])
            e=mid-1;
        else
            s=mid+1;
    }
    return ans;
}

int last(vector<int> &v,int x){
    int n=v.size();
    int s=0,e=n-1,ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]==x){
            ans=mid;
            s=mid+1;
        }
        else if(x<v[mid])
            e=mid-1;
        else
            s=mid+1;
    }
    return ans;
}

int total(vector<int> &v,int x){
    int f=first(v,x);
    int l=last(v,x);
    if(f==-1){
        // means element not present
        return 0;
    }
    return l-f+1;
}

int main(){
    vector<int> v={1, 1, 2, 2, 2, 2, 3};
    cout<<total(v,2)<<" "<<total(v,4);
}