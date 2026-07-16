#include<bits/stdc++.h>
using namespace std;

string reorg(string s){
    int n=s.length();
    
    unordered_map<char,int> mp;
    int maxfreq=-1;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
        maxfreq=max(maxfreq,mp[s[i]]);
    }
    if(maxfreq>(n+1)/2)
        return "";
    
    priority_queue<pair<int,char>> pq;   // freq-char
    for(auto it:mp)
        pq.push(make_pair(it.second,it.first));
    
    int i=0; // put alternate basis
    // if cross boundary start from odd index
    while(!pq.empty()){
        int freq=pq.top().first;
        char ch=pq.top().second;
        while(freq>0){
            i=(i>=n)?1:i;
            s[i]=ch;
            i+=2;
            freq--;
        }
        pq.pop();
    }
    return s;
}

int main(){
    string s="aaabc";
    cout<<reorg(s);
}