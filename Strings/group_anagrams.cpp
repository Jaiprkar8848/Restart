#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagram(vector<string> v){
    unordered_map<string,vector<string>> mp;
    /*
    aet -> eat,ate
    abt -> bta,bat
    .. 
    */
   for(auto s:v){
    string temp=s;
    sort(temp.begin(),temp.end());
    mp[temp].push_back(s);
   }
   vector<vector<string>> ans;
   for(auto it:mp){
    ans.push_back(it.second);
   }
   return ans;
}

int main(){
    vector<string> v={"listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"};
    vector<vector<string>> ans=groupAnagram(v);
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(auto it:ans[i]){
            cout<<it<<" ";
        }
        cout<<"]"<<endl;
    }
}