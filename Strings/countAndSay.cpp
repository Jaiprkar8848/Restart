#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n){
    if(n==1) return "1";
    string prev=countAndSay(n-1);
    int len=prev.length();
    int cnt=1; // becz at least 1 toh hoga hi na count
    string t="";
    for(int i=1;i<len;i++){
        if(prev[i]==prev[i-1])
            cnt++;
        else{
            // change hua h character toh hume uski freq(cnt) and vo char append krna h
            t+=to_string(cnt)+prev[i-1];
            // again count ko 1 krdenge kyoki new char start hoga
            cnt=1;
        }
    }
    // end wala loop ke through append nhi so use alag se kr rhe
    t+=to_string(cnt)+prev[len-1];
    return t;
}

int main(){
    cout<<countAndSay(4)<<endl;
    cout<<countAndSay(5)<<endl;
}