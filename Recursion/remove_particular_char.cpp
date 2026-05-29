#include<iostream>
#include<cstring>
using namespace std;

void rmv_particular(char input[]){
    int n=strlen(input);
    if(n==0) return;
    if(input[0]=='x'){
        for(int i=0;i<n;i++)
            input[i]=input[i+1];
        rmv_particular(input);
    }
    else{
        rmv_particular(input+1);
    }
}

int main(){
    char input[]="xabcxd";
    rmv_particular(input);
    cout<<input;
}