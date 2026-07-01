#include<bits/stdc++.h>
using namespace std;

/*
go through all subarray and find peaks -> O(n*k)
*/

void findPeaks1(vector<int> v,int k){
    int n=v.size();
    // calculate for first window
    int peak=0;
    // first and last element of window can't be peak
    for(int i=1;i<k-1;i++){
        if(v[i]>v[i+1] && v[i]>v[i-1])
            peak++;
    }
    int maxpeak=peak;
    int l=0,r=k-1;  // window
    int winStart=0;
    while(r<=n-2){    // becz if we do r++ after this then it goes out of array
        l++;
        // checking the first element of the window is peak or not for prev window
        if(v[l]>v[l+1] && v[l]>v[l-1])
            peak--;
        // now last element of prev window can be a peak
        if(v[r]>v[r+1] && v[r]>v[r-1])
            peak++;
        r++;  // sliding
        if(peak>maxpeak){
            maxpeak=peak;
            winStart=l;
        }
    }
    cout<<"Max Peak : "<<maxpeak<<endl;
    cout<<"window start : "<<winStart<<endl;
    cout<<"window end : "<<winStart+k-1<<endl;
}

void findPeaks2(vector<int> &v,int k){
    int n=v.size();
    int peak=0;
    for(int i=1;i<k-1;i++){
        if(v[i]>v[i-1] && v[i]>v[i+1])
            peak++;
    }
    int maxpeak=peak;
    int winStart=0;
    for(int i=k;i<n;i++){
        int add_index=i;
        int remove_index=i-k;
        // check first element of window whether it was peak previously
        if(v[remove_index+1]>v[remove_index+2] && v[remove_index+1]>v[remove_index])
            peak--;
        // check element before add_index whether it is peak or not
        // becz last window main vo peak nhi tha but isme ho skta h
        if(v[add_index-1]>v[add_index] && v[add_index-1]>v[add_index-2])
            peak++;
        if(peak>maxpeak){
            maxpeak=peak;
            winStart=remove_index+1;
        }
    }
    cout<<"Max Peak : "<<maxpeak<<endl;
    cout<<"window start : "<<winStart<<endl;
    cout<<"window end : "<<winStart+k-1<<endl;
}

int main(){
    vector<int> v={3,2,3,2,1};
    int k=3;
    findPeaks1(v,k);
    cout<<"-----------------------"<<endl;
    findPeaks2(v,k);
}