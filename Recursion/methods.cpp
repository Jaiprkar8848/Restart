#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v={5,13,1,32,13,6,89};
    sort(v.begin(),v.end());
    cout<<*(lower_bound(v.begin(),v.end(),14))<<endl;
    cout<<*(lower_bound(v.begin(),v.end(),93))<<endl;
    cout<<*(max_element(v.begin(),v.end()))<<endl;
    cout<<count(v.begin(),v.end(),13)<<endl;
    cout<<count(v.begin(),v.end(),93)<<endl;
    cout<<accumulate(v.begin(),v.end(),10)<<endl;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}