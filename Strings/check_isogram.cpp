#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    int n=s.length();
    vector<int> freq(26,0);
    for(int i=0;i<n;i++){
        int idx=s[i]-'a';
        freq[idx]++;
        if(freq[idx]>1)
            return 0;
    }
    return 1;
}

int main(){
    cout<<check("machine")<<endl;
    cout<<check("jaiprakash");
}