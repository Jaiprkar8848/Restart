#include<bits/stdc++.h>
using namespace std;

/*
Brute -> find all subarray of size k ->  n-k+1, find their sum
O((n-k+1)*(k))
*/
int maxSubarraySum(vector<int> &v,int k){
    int n=v.size();
    int windowStart=0;
    int windowEnd=windowStart+k-1;
    int sum=0;
    for(int i=windowStart;i<=windowEnd;i++)
        sum+=v[i];
    int currWindowSum=sum;
    while(windowEnd<n){
        if(windowEnd+1<n) 
            currWindowSum=currWindowSum+v[windowEnd+1]-v[windowStart];
        sum=max(sum,currWindowSum);
        windowStart++,windowEnd++;
    }
    return sum;
}

int way2(vector<int>&v,int k){
    int n=v.size();
    int sum=0;
    // first window sum
    for(int i=0;i<k;i++)
        sum+=v[i];
    int ans=max(INT_MIN,sum);
    // go through the endpoint of every window
    // or slide the window by endpoint
    for(int i=k;i<n;i++){
        int add_index=i;
        int remove_index=i-k;
        sum=sum+v[add_index]-v[remove_index];
        ans=max(ans,sum);
    }
    return ans;
}

int main(){
    vector<int> v={9479,488,2374,1583,5863,7811,6916,1685,3960};
    int k=5;
    cout<<maxSubarraySum(v,k)<<" "<<way2(v,k);
}