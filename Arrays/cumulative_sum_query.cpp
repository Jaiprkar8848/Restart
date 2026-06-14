/*
3
1 4 1
3
1 1
1 2
0 2

4
5 
6
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int> pref_sum(n,0);
    pref_sum[0]=v[0];
    for(int i=1;i<n;i++)
        pref_sum[i]=pref_sum[i-1]+v[i];
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(a!=0)
            cout<<pref_sum[b]-pref_sum[a-1];
        else    
            cout<<pref_sum[b];
        cout<<endl;
    }
}