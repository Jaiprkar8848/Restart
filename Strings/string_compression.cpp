#include<bits/stdc++.h>
using namespace std;

int stringComp(vector<char> &v){
    int n=v.size();
    int i,cnt=1;
    string s="";
    for(i=1;i<n;i++){
        if(v[i]!=v[i-1]){
            // character change
            s+=v[i-1];
            if(cnt>1)
                s+=to_string(cnt);
            // reset count becz new character
            cnt=1;
        }
        else
            cnt++;
    }
    // for the last one
    s+=v[i-1];
    if(cnt>1)
        s+=to_string(cnt);
    // filling in  original array
    i=0;
    for(auto it:s)
        v[i++]=it;
    return i;
}

int main(){
    vector<char> v={'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int n=stringComp(v);
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<' ';
}