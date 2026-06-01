#include<iostream>
#include<vector>
using namespace std;

void helper(int idx,string &input,string &curr,vector<string> &mp,vector<string> &ans){
    if(idx==input.size()){
        ans.push_back(curr);
        return;
    }
    int index=input[idx]-'0';
    string corresponding=mp[index];
    for(char ch:corresponding){
        curr+=ch;
        helper(idx+1,input,curr,mp,ans);
        curr.pop_back();   // backtrack
    }
}

vector<string> letterCombinations(string input){
    vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string curr="";
    helper(0,input,curr,mp,ans);
    return ans;
}

int main(){
    string input;
    cin>>input;
    vector<string> ans=letterCombinations(input);
    for(auto it:ans)
        cout<<it<<endl;
}