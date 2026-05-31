#include<iostream>
#include<vector>
using namespace std;

void permute(int idx,string input,vector<string> &ans){
    if(idx==input.size()){
        ans.push_back(input);
        return;
    }
    for(int i=idx;i<input.size();i++){
        swap(input[i],input[idx]);
        permute(idx+1,input,ans);
        swap(input[i],input[idx]);
    }
}

int main(){
    string input;
    cin>>input;
    vector<string> ans;
    permute(0,input,ans);
    for(auto it:ans)
        cout<<it<<endl;
}