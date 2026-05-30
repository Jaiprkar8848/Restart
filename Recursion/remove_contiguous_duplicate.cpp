#include<iostream>
#include<cstring>
using namespace std;

void rmv_conti_duplicates(char input[]){
    int n=strlen(input);
    if(n==0 || n==1) return;
    // at least 2 char
    if(input[0]==input[1]){
        // shift towards left
        for(int i=0;i<n;i++)
            input[i]=input[i+1];
        rmv_conti_duplicates(input);
    }
    else{
        rmv_conti_duplicates(input+1);
    }
}

int main(){
    char input[100];
    cin>>input;
    rmv_conti_duplicates(input);
    cout<<input;
}