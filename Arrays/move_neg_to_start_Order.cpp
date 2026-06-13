#include<iostream>
#include<vector>
using namespace std;

vector<int> move_neg1(vector<int> &v,int n){
    vector<int> temp(n,0);
    // put negative 
    int k=0;
    for(int i=0;i<n;i++){
        if(v[i]<0) temp[k++]=v[i];
    }
    for(int i=0;i<n;i++){
        if(v[i]>0) temp[k++]=v[i];
    }
    return temp;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int> v1=move_neg1(v,n);
    for(int i=0;i<n;i++)
        cout<<v1[i]<<" ";
}