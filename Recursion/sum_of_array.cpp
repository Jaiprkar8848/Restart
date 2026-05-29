#include<iostream>
using namespace std;

int findSum(int a[],int n){
    if(n==0) return 0;
    if(n==1) return a[0];
    return a[0]+findSum(a+1,n-1);
}

int main(){
    int a[]={1,2,3,4,5};
    cout<<findSum(a,5);
}