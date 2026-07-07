#include<bits/stdc++.h>
using namespace std;

bool check(string &s1,string &s2){
    if(s1.length()!=s2.length())
        return 0;
    // all rotation are someway substring of this concatenated s1
    s1+=s1;
    return s1.find(s2)!=string::npos;
}

int main(){
    string s1="abcde";
    string s2="cdeba";

    if(check(s1,s2))
        cout<<"Valid Rotation";
    else
        cout<<"Invalid Rotation";
}