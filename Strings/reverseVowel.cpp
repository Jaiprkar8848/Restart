#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A'
        || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return 1;
        return 0;
}

string revV(string &s){
    int st=0,e=s.length()-1;
    while(st<e){
        if(!isVowel(s[st])) st++;
        else if(!isVowel(s[e])) e--;
        else swap(s[st++],s[e--]);
    }
    return s;
}

int main(){
    string s="practice";
    cout<<revV(s);
}