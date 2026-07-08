#include<bits/stdc++.h>
using namespace std;

/*
Go through all substrings and check whether they are palindrome or not
find the longest from them
*/

string longestPalindromicSubstring(string &s){
    int n=s.size();
    int start=0; // for maintaining start of longest palindormic substring
    int maxlen=1; // 1 length ki toh hogi hi aur vo bhi first index se
    // for even length palindrome
    // ab|ba -> there is no mid kind of thing or we can say for this we compare adjacent
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1])
            continue;
        int left=i-1;
        int right=i;
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>maxlen){
                start=left;
                maxlen=right-left+1;
            }
            left--,right++;
        }
    }
    // for odd length palindrom
    // aba -> mid h jiske left and right same h cheeze that means hume i-1 and i+1 ko dekhna h
    for(int i=1;i<n-1;i++){
        if(s[i-1]!=s[i+1])
            continue;
        int left=i-1;
        int right=i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>maxlen){
                start=left;
                maxlen=right-left+1;
            }
            left--,right++;
        }
    }
    return s.substr(start,maxlen);
}

int main(){
    string s="forgeeksskeegfor";
    cout<<longestPalindromicSubstring(s);   
}