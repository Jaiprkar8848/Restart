#include<bits/stdc++.h>
using namespace std;

bool way1(string s,string t){
    if(s.length()!=t.length())
        return 0;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}

bool way2(string s,string t){
    if(s.length()!=t.length())
        return 0;
    vector<int> freq(256,0);
    for(int i=0;i<s.length();i++){
        freq[s[i]]++;
        freq[t[i]]--;
    }
    for(int i=0;i<256;i++){
        if(freq[i]!=0)
            return 0;
    }
    return 1;
}

int main(){
    cout<<way1("anagram","nagaram")<<endl;
    cout<<way2("rat","car")<<endl;
}