#include<iostream>
#include<vector>
using namespace std;
// sort(begin,end,cmp)
// whenever cmp return false internally swapping tb hogi
// jo chahte ho whi likho
// inc -> return a<b 
// dec -> return a>b
// cmp is pointer to a function or function pointer -> function ka name address

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first){
        if(a.first>b.first)
            return true;
        return false;
    }
    else{
        if(a.second<b.second)
            return true;
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(comp(v[i],v[j]))
                swap(v[i],v[j]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}