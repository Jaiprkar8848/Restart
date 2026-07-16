#include<bits/stdc++.h>
using namespace std;

int firstOcc(string s,string t){
    if(t.size()>s.size())
        return -1;
    int n=s.size(),m=t.size();
    for(int i=0;i<=n-m;i++){
        // start index jaha se check krna h
        int j=0;
        while(j<m){
            if(s[i+j]!=t[j])
                break;
            else
                j++;
        }
        if(j==m)
            return i;
    }
    return -1;
}

int main(){
    string org="adbutsad";
    cout<<firstOcc(org,"sad")<<" "<<firstOcc(org,"jp");
}