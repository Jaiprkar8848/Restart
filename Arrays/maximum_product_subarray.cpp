#include<bits/stdc++.h>
using namespace std;

/*
Brute Force - Go through all subarrays
*/

int maxProd(vector<int> &v){
    int n=v.size();
    int maxi=v[0],mini=v[0];   // product ending at v[i]
    int ans=max(mini,maxi);
    for(int i=1;i<n;i++){
        if(v[i]<0){
            // +ve * -ve -> decrease
            // -ve * -ve -> increase
            swap(maxi,mini);
        }
        maxi=max(v[i],maxi*v[i]);   // 2 ways -> either include in subarray or start new subarray from it
        mini=min(v[i],mini*v[i]);   // for -ve number
        ans=max(ans,maxi);
    }
    return ans;
}

int main(){
    vector<int> v={-2, 6, -3, -10, 0, 2};
    cout<<maxProd(v);
}