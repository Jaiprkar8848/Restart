#include<iostream>
#include<vector>
using namespace std;

void move_neg(vector<int> &v,int n){
    // partition
    int k=-1; // to track negative or fill negative
    for(int i=0;i<n;i++){
        if(v[i]<0){
            k++;
            swap(v[k],v[i]);
        }
    }   
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    move_neg(v,n);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
}