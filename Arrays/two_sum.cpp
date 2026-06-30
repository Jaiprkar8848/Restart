#include<bits/stdc++.h>
using namespace std;

vector<int> way1(vector<int> &v,int target){
    // brute force
    vector<int> ans;
    int n=v.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]+v[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> way2(vector<int> &v,int target){
    // nlogn
    int n=v.size();
    vector<int> ans;
    vector<pair<int,int>> temp; // {ele,org_idx}
    for(int i=0;i<n;i++)
        temp.push_back(make_pair(v[i],i));
    sort(temp.begin(),temp.end());  // default on the first element basis
    for(int i=0;i<n;i++){
        int to_find=target-v[i];
        // binary search
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(temp[mid].first==to_find && temp[mid].second!=i){
                ans.push_back(i);
                ans.push_back(temp[mid].second);
                return ans;
            }
            else if(temp[mid].first<to_find) s=mid+1;
            else e=mid-1;
        }
    }
    return ans;
}

vector<int> way3(vector<int> &v,int target){
    // O(N)
    int n=v.size();
    vector<int> ans;
    unordered_map<int,int> mp; // value-idx
    for(int i=0;i<n;i++){
        int to_find=target-v[i];
        if(mp.find(to_find)!=mp.end()){
            // found
            ans.push_back(i);
            ans.push_back(mp[to_find]);
        }
        else
            mp[v[i]]=i;
    }
    return ans;
}

int main(){
    vector<int> v={2,7,15,11};
    vector<int> a=way1(v,9);
    cout<<a[0]<<" "<<a[1]<<endl;
    vector<int> b=way2(v,22);
    cout<<b[0]<<" "<<b[1]<<endl;
    vector<int> c=way3(v,18);
    cout<<c[0]<<" "<<c[1]<<endl;
}