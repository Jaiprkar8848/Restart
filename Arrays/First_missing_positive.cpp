#include<bits/stdc++.h>
using namespace std;

int way1(vector<int> &v){
    int n=v.size();
    // if agar ye size n size ka array h jisme sirf positive hote
    // so vo 1 to n hote
    // we check for 1 to n 
    // at any number if it is not present that will be our missing positive
    // if all are present then missing positive will be n+1
    for(int num=1;num<=n;num++){
        int i;
        for(i=0;i<n;i++){
            if(v[i]==num)
                break;
        }
        if(i==n) // means num not found
            return num;
    }
    return n+1;
}

int way2(vector<int> &v){
    // searching is easier if v is sorted
    sort(v.begin(),v.end());
    int n=v.size();
    for(int num=1;num<=n;num++){
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(v[mid]==num)
                break;
            else if(v[mid]>num)
                e=mid-1;
            else 
                s=mid+1;
        }
        if(s>e)  // num not found;
            return num;
    }
    return n+1;
}

int way3(vector<int> &v){
    int n=v.size();
    int i=0;
    while(i<n){
        int ele=v[i];
        int correct_pos=ele-1;
        if(ele>=1 && ele<=n){
            if(v[i]!=v[correct_pos])
                swap(v[i],v[correct_pos]);
            else
                i++;
        }
        else
            i++;
    }

    /*
    for(int i=0;i<n;i++){
        int ele=v[i];
        int chair=ele-1;
        if(ele>=1 && ele<=n){
            if(v[i]!=v[chair]){
                swap(v[i],v[chair]);
                i--;  // to check the current element again, becz for loop is doing i++ every time
            }
        }
    }*/
    for(int i=0;i<n;i++){
        if(v[i]!=i+1)
            return i+1;
    }
    return n+1;
}

int main(){
    vector<int> v={3,4,-1,1};
    cout<<way1(v)<<endl;
    cout<<way2(v)<<endl;
    cout<<way3(v)<<endl;
}