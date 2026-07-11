#include<bits/stdc++.h>
using namespace std;

bool isLetter(char x){
    return ((x>=97 && x<=122) || (x>=65 && x<=90));
}

string revL(string &s){
    int st=0,e=s.length()-1;
    while(st<e){
        if(!isLetter(s[st])) st++;
        else if(!isLetter(s[e])) e--;
        else swap(s[st++],s[e--]);
    }
    return s;
}

int main(){
    string s="a-bC-dEf-ghIj";
    cout<<revL(s);
}