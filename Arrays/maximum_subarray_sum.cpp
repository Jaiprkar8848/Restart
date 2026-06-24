#include<bits/stdc++.h>
using namespace std;

int way1(vector<int> &v){
    int n=v.size();
    int maxsum=INT_MIN,sum;
    for(int s=0;s<n;s++){
        for(int e=s;e<n;e++){
            sum=0;
            for(int k=s;k<=e;k++){
                sum+=v[k];
            }
            maxsum=max(sum,maxsum);
        }
    }
    return maxsum;
}

int way2(vector<int> &v){
    int n=v.size();
    int maxsum=INT_MIN,curr_subarray_sum;
    vector<int> pref_sum(n,0);
    pref_sum[0]=v[0];
    for(int i=1;i<n;i++)
        pref_sum[i]=pref_sum[i-1]+v[i];
    for(int s=0;s<n;s++){
        for(int e=s;e<n;e++){
            if(s==0)
                curr_subarray_sum=pref_sum[e];
            else
                curr_subarray_sum=pref_sum[e]-pref_sum[s-1];
            maxsum=max(maxsum,curr_subarray_sum);
        }
    }
    return maxsum;
}

int way3(vector<int> &v){
    // kadane's algorithm
    int res=v[0];
    int n=v.size();
    int maxSum_ending_at_particular_element=v[0];
    for(int i=1;i<n;i++){
        // 2 cases
        // include element or start new subarray from that element
        maxSum_ending_at_particular_element=max(maxSum_ending_at_particular_element+v[i],v[i]);
        res=max(maxSum_ending_at_particular_element,res);
    }
    return res;
}

int way4(vector<int> &v){
    int ans=v[0];
    int curr_sum=v[0];
    int n=v.size();
    for(int i=1;i<n;i++){
        if(curr_sum>=0)
            curr_sum+=v[i];
        else
            curr_sum=0+v[i];  // sum negative hoga toh usse acha 0 better
        ans=max(ans,curr_sum);
    }
    return ans;
}

int main(){
    vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
    cout<<way1(v)<<endl;
    cout<<way2(v)<<endl;
    cout<<way3(v)<<endl;
    cout<<way4(v);
}