#include<iostream>
#include<vector>
using namespace std;

void rev1(vector<int> &v,int n){
    for(int i=0;i<n/2;i++)
        swap(v[i],v[n-1-i]);
}

void rev2(vector<int> &v,int n){
    int s=0,e=n-1;
    while(s<e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    rev1(v,n);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    rev2(v,n);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}