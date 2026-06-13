#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int> &v,int n){
    int z=0,o=0,t=0;
    for(int i=0;i<n;i++){
        if(v[i]==0) z++;
        if(v[i]==1) o++;
        if(v[i]==2) t++;
    }
    int k=0;
    for(int i=1;i<=z;i++)
        v[k++]=0;
    for(int i=1;i<=o;i++)
        v[k++]=1;
    for(int i=1;i<=t;i++)
        v[k++]=2;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort012(v,n);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
}