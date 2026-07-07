/*
A phrase is a palindrome if, 
after converting all uppercase letters into lowercase letters and 
removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.
*/

#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &s){
    int n=s.length();
    int st=0,e=n-1;
    while(st<e){
        // check whether char pointing by st is alphanumeric
        bool checkst=(s[st]>=65 && s[st]<=90) || (s[st]>=97 && s[st]<=122) || (s[st]>=48 && s[st]<=57);
        // check whether char pointing by e is alphanumeric
        bool checke=(s[e]>=65 && s[e]<=90) || (s[e]>=97 && s[e]<=122) || (s[e]>=48 && s[e]<=57);
        if(checkst==false){
            st++;
            continue;
        }
        if(checke==false){
            e--;
            continue;
        }
        // means both are alphanumeric
        // convert into lowercase if required
        if(s[st]>=65 && s[st]<=90) s[st]+=32;
        if(s[e]>=65 && s[e]<=90) s[e]+=32;

        // now compare
        if(s[st]!=s[e])
            return false;
        st++,e--;
    }
    return true;
}

int main(){
    string s="A man, a plan, a canal: Panama";
    if(checkPalindrome(s))
        cout<<"Yes it is a valid palindromic string";
    else
        cout<<"Not a valid palindromic string";
}