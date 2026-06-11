#include<iostream>
#include<vector>
using namespace std;

vector<int> way1(vector<int> v,int n){
    // creeate
    vector<int> temp(n,0);
    int k=0;
    for(int i=0;i<n;i++){
        if(v[i]!=0)
            temp[k++]=v[i];
    }
    return temp;
}

void way2(vector<int> &v,int n){
    int k=0; // for placing non zeros in same array
    for(int i=0;i<n;i++){
        if(v[i]!=0)
            v[k++]=v[i];
    }
    while(k<n)      // putting zeros in remaining
        v[k++]=0;
}

int main(){
    vector<int> v={7,0,2,0,3,0,5};
    vector<int> v1=way1(v,v.size());
    for(auto it:v1)
        cout<<it<<" ";
    cout<<endl;
    way2(v,v.size());
    for(auto it:v)
        cout<<it<<" ";
}