#include<bits/stdc++.h>
using namespace std;

bool iso(string s,string t){
    int m=s.length();
    int n=t.length();
    if(m!=n)
        return 0;
    unordered_map<char,char> mp1,mp2;
    for(int i=0;i<n;i++){
        if(mp1.find(s[i])==mp1.end() && mp2.find(t[i])==mp2.end()){
            // means it is the first time they are going to map
            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        else if(mp1[s[i]]!=t[i])
            return 0;
    }
    return 1;
}

int main(){
    cout<<iso("egg","add")<<" "<<iso("f11","b23");
}