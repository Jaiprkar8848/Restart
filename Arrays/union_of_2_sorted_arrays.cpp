#include<bits/stdc++.h>
using namespace std;

vector<int> way1(vector<int> &a,vector<int> &b){
    int m=a.size();
    int n=b.size();
    vector<int> res;
    // iterate to first array
    for(int i=0;i<m;i++){
        // checking whether result contain that element or not
        int j;
        for(j=0;j<res.size();j++){
            if(a[i]==res[j])
                break;
        }
        if(res.size()==j) res.push_back(a[i]);
    }
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<res.size();j++){
            if(b[i]==res[j])
                break;
        }
        if(res.size()==j) res.push_back(b[i]);
    }
    sort(res.begin(),res.end());
    return res;
}

vector<int> way2(vector<int> &a,vector<int> &b){
    int i=0,j=0,k=0;
    int m=a.size(),n=b.size();
    vector<int> c(m+n,0);
    while(i<m && j<n){
        while(i>0 && a[i]==a[i-1])
            i++;
        while(j>0 && b[j]==b[j-1])
            j++;
        if(i>=m || j>=n) break;
        if(a[i]<b[j])
            c[k++]=a[i++];
        else if(a[i]>b[j])
            c[k++]=b[j++];
        else{
            c[k]=a[i];
            i++,j++,k++;
        }
    }
    while(i<m){
        if(i>0 && a[i]==a[i-1]) 
            i++;
        else 
            c[k++]=a[i++];
    }
    while(j<n){
        if(j>0 && b[j]==b[j-1])
            j++;
        else
            c[k++]=b[j++];
    }
    c.resize(k);
    return c;
}

int main(){
    vector<int> a={2,2,3,4,5};
    vector<int> b={1,1,2,3,4};
    vector<int> ans1=way1(a,b);   
    for(auto it:ans1)
        cout<<it<<" ";
    cout<<endl;
    vector<int> ans2=way2(a,b);
    for(auto it:ans2)
        cout<<it<<" ";
}