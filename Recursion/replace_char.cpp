// replace x with aab
#include<iostream>
#include<cstring>
using namespace std;

void replace(char input[]){
    int n=strlen(input);
    if(n==0)
        return;
    if(input[0]=='x'){
        for(int i=n;i>0;i--)
            input[i+2]=input[i];
            // +2 -> comes from aab size - 1
            // becz every char shift by 2
        input[0]='a';
        input[1]='a';
        input[2]='b';
        replace(input+3);
    }
    else{
        replace(input+1);
    }
}

void generalize(char input[],char from,char to[]){
    int n=strlen(input);
    if(n==0)
        return;
    if(input[0]==from){
        int l=strlen(to);
        for(int i=n;i>0;i--)
            input[i+l-1]=input[i];
        for(int i=0;i<l;i++)
            input[i]=to[i];
        generalize(input+l,from,to);  
    }
    else{
        generalize(input+1,from,to);
    }
}

int main(){
    char input[100]="xabcdx";
    replace(input);
    cout<<input<<endl;
    char inp[100];
    char to[100];
    cin>>inp;
    cin>>to;
    generalize(inp,'x',to);
    cout<<inp;
    return 0;
}