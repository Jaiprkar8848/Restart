#include<iostream>
using namespace std;

bool isSorted(int a[],int n){
    if(n==0 || n==1) return 1;
    if(a[0]>a[1]) return 0;
    return isSorted(a+1,n-1);
}

int main(){
    int a[]={0,1,2,4,5,6};
    cout<<isSorted(a,6);
}