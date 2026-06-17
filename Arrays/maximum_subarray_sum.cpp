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

int main(){
    vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
    cout<<way1(v)<<endl;
    cout<<way2(v)<<endl;
}