#include<iostream>
using namespace std;

void generate(int a,int b,string tillnow){
    if(a==0 && b==0){
        cout<<tillnow<<endl;
        return;
    }
    if(a>0)
        generate(a-1,b,tillnow+'a');
    if(b>0)
        generate(a,b-1,tillnow+'b');
}

int main(){
    int n;
    cin>>n;
    generate(n,n,"");
}