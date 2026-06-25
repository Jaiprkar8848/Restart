#include<bits/stdc++.h>
using namespace std;

int majority(vector<int> &v){
    int n=v.size();
    int cnt=1;
    int currCand=v[0];
    for(int i=1;i<n;i++){
        if(v[i]==currCand) cnt++;
        else cnt--;
        if(cnt==0){
            // abtak array main koi majorit nhi h
            // abse new array start krte h
            currCand=v[i];
            cnt=1;
        }
    }
    cnt=0;
    for(int i=0;i<n;i++){
        if(currCand==v[i]) cnt++;
    }

    if(cnt>n/2) return currCand;
    else return -1;
}

int main(){
    vector<int> v={1, 1, 2, 1, 3, 5, 1};
    cout<<majority(v);
}