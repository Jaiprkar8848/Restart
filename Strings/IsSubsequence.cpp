#include<bits/stdc++.h>
using namespace std;

/*
Brute - Find all subsequence and check -> 2 power n
*/

bool isSub1(string &s,string &t){
    int n=s.length();
    int m=t.length();
    if(m>n)          // subsequence can't be greater than original string
        return 0;
    int i=0,j=0;
    while(i<n && j<m){
        if(s[i]==t[j])
            j++;
        i++;
    }
    return j==m;
}

bool isSub2(string &s,string &t){
    int n=s.length();
    int m=t.length();
    int i=0,j=0;
    for(i=0;i<n && j<m;i++){
        if(s[i]==t[j])
            j++;
    }
    return j==m;
}

int main(){
    string s="ahbgdc",t="abc";
    if(isSub1(s,t))
        cout<<"Yes";
    else    
        cout<<"No"; 
    cout<<endl;
    string r="axc";
    if(isSub2(s,r))
        cout<<"Yes";
    else
        cout<<"No";
}