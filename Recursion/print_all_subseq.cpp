#include<iostream>
using namespace std;

void printSubseq(string s,string tillNow){
    if(s.size()==0){
        cout<<tillNow<<endl;
        return;
    }
    printSubseq(s.substr(1),tillNow);
    printSubseq(s.substr(1),tillNow+s[0]);
}

void printSubseq1(int idx,string s,string tillNow){
    if(idx==s.size()){
        cout<<tillNow<<endl;
        return;
    }
    printSubseq1(idx+1,s,tillNow+s[idx]);
    printSubseq1(idx+1,s,tillNow);
}

int main(){
    string s="abc";
    printSubseq(s,"");
    cout<<"-------"<<endl;
    printSubseq1(0,s,"");
}