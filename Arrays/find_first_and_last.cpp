#include<bits/stdc++.h>
using namespace std;

int first(vector<int> &v,int x){
    int n=v.size();
    int s=0,e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]==x){
            ans=mid;
            // ho skta h yehi first occ ho
            // ya isse pehle bhi ho skti h
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
    int s=0,e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]==x){
            ans=mid;
            // ho skta h yehi last occ ho
            // ya iske aage bhi ho last
            s=mid+1;
        }
        else if(v[mid]>x)
            e=mid-1;
        else 
            s=mid+1;
    }
    return ans;
}

vector<int> find_occ(vector<int> &v,int x){
    vector<int> ans(2,-1);
    ans[0]=first(v,x);
    ans[1]=last(v,x);
    return ans;
}

int main(){
    vector<int> v={5,7,7,8,8,10};
    vector<int> ans=find_occ(v,8);
    cout<<ans[0]<<" "<<ans[1];
}