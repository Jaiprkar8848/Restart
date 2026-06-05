#include<iostream>
#include<vector>
using namespace std;

// void helper(int idx,string s,string curr,vector<string> &ans){
//     if(idx==s.size()-1){
//         curr+=s[idx];
//         ans.push_back(curr);
//         return;
//     }
//     helper(idx+1,s,curr+s[idx]+' ',ans);
//     helper(idx+1,s,curr+s[idx],ans);
// }

void helper(int idx,string s,string &curr,vector<string> &ans){
    if(idx==s.size()-1){
        ans.push_back(curr+s[idx]);
        return;
    }
    curr+=s[idx];
    curr+=' ';
    helper(idx+1,s,curr,ans);
    curr.pop_back();
    helper(idx+1,s,curr,ans);
    curr.pop_back();
}

vector<string> permutation(string s){
    vector<string> ans;
    string curr="";
    helper(0,s,curr,ans);
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string> ans=permutation(s);
    for(auto it:ans)
        cout<<it<<endl;
}