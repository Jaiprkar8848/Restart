/*
q queries
l,r -> find gcd excluding l...r

3 3
2 6 9
1 1 -> 3
2 2 -> 1
2 3 -> 2
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    // find prefixGcd
    // preGcd[i]=gcd(V[0..i])
    vector<int> preGcd(n,0);
    preGcd[0]=v[0];
    for(int i=1;i<n;i++){
        preGcd[i]=__gcd(preGcd[i-1],v[i]);
    }
    // find suffixGcd
    vector<int> sufGcd(n+1,0);
    sufGcd[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--){
        sufGcd[i]=__gcd(sufGcd[i+1],v[i]);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=__gcd(preGcd[l-1],sufGcd[r+1]);
        cout<<ans<<endl;
    }
}