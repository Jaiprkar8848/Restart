#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int mid, int r, int &inv) {
    int n1 = mid - l + 1;
    vector<int> a(n1);
    for (int i = 0; i < n1; i++)
        a[i] = v[l + i];

    int n2 = r - mid;
    vector<int> b(n2);
    for (int j = 0; j < n2; j++)
        b[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            v[k++] = a[i++];
        } else {
            v[k++] = b[j++];
            inv += n1 - i;
        }
    }

    while (i < n1) v[k++] = a[i++];
    while (j < n2) v[k++] = b[j++];
}

void msort(vector<int> &v, int l, int r, int &inv) {
    if (l >= r)
        return;
    int mid=l+(r-l)/2;
    msort(v,l,mid,inv);
    msort(v,mid+1,r,inv);
    merge(v,l,mid,r,inv);
}

int main(){
    vector<int> v={2, 4, 1, 3, 5};
    int inv=0;
    msort(v,0,v.size()-1,inv);
    cout<<inv;
}