#include<iostream>
using namespace std;

int subseq(string s,string output[]){
    if(s.size()==0){
        output[0]=" ";
        return 1;
    }
    // bc ka answer recursion le aaya -> ["",b,c,bc]
    int smallSize=subseq(s.substr(1),output);
    // append first char to every string of answer of bc
    // size become double
    for(int i=0;i<smallSize;i++)
        output[i+smallSize]=s[0]+output[i];
    return 2*smallSize;
}

int main(){
    string s="abc";
    string *output=new string[100];
    int outputSize=subseq(s,output);
    for(int i=0;i<outputSize;i++)
        cout<<output[i]<<endl;
}