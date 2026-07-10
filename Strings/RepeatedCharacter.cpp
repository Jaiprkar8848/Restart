#include<bits/stdc++.h>
using namespace std;

char find(string &s){
    int n=s.length();
    vector<int> freq(256,0);
    for(int i=0;i<n;i++)
        freq[s[i]]++;
    for(int i=0;i<n;i++){
        if(freq[s[i]]>1)
            return s[i];
    }
    return '#';
}

int main(){
    string s="geeksforgeeks";
    cout<<find(s);
}