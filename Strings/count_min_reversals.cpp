#include<bits/stdc++.h>
using namespace std;

int countMin(string &s){
    int n=s.length();
    if(n%2){
        // odd length -> impossible to balance
        return -1;
    }
    // n=even -> odd+odd or even+even
    // even -> require even/2
    // odd -> require odd/2 + 1
    // koi string ka part balanced h toh use hume nhi chedna
    // only push open kyoki open is waiting for close
    stack<char> st;
    int open=0,close=0;
    for(int i=0;i<n;i++){
        if(s[i]=='{'){
            st.push(s[i]);
            open++;
        }
        else{
            if(st.empty()){
                // count closed
                close++;
            }
            else{
                st.pop();
                open--;
            }
        }
    }
    open=(open%2)?(open/2+1):(open/2);
    close=(close%2)?(close/2+1):(close/2);
    return open+close;
}

int main(){
    string a="}}}{{}}{{{{{";
    string b="}}{";
    cout<<countMin(a)<<" "<<countMin(b);
}