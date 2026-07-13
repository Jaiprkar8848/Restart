#include<bits/stdc++.h>
using namespace std;

string equi(string &s){
    vector<string> v={"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777",
        "7777","8","88","888","9","99","999","9999"};
    string answer="";
    for(int i=0;i<s.length();i++){
        if(s[i]==' ')
            answer+='0';
        else{
            int index=s[i]-'A';
            answer+=v[index];
        }
    }
    return answer;
}

int main(){
    string s;
    getline(cin,s);
    cout<<equi(s)<<endl;
}