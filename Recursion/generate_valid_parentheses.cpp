#include<iostream>
using namespace std;

void generate(int open,int close,string tillnow){
    if(open==0 && close==0){
        cout<<tillnow<<endl;
        return;
    }
    if(open>0){
        generate(open-1,close,tillnow+'(');
    }
    if(close>0 && open<close){
        generate(open,close-1,tillnow+')');
    }
}

int main(){
    int n;
    cin>>n;
    generate(n,n,"");
}