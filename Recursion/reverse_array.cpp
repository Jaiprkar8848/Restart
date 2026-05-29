#include<iostream>
using namespace std;

void reverse_array(int a[],int n){
    if(n==0 || n==1) return;
    swap(a[0],a[n-1]);
    reverse_array(a+1,n-2);
}
int main(){
    int a[]={1,2,3,4,5,6};
    reverse_array(a,6);
    for(int i=0;i<6;i++)
        cout<<a[i]<<" ";
}