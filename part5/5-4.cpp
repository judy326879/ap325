#include <iostream>
#include <vector>
typedef long long LL;
using namespace std;
//大到小的數列個數
LL inv(vector<int> &a, int left, int right){
    if(left+1>=right) return 0;
    int m = (left+right)/2;
    LL w = inv(a, left, m) + inv(a, m, right);
    LL cross = 0;
    vector<int> temp(right-left);
    int j = m, k = 0;
    for(int i=left;i<m;++i){      //i = left ~ m-1
        //right < left -> push right
        while(j<right&&a[j]<a[i]) //j = m
            temp[k++] = a[j++];   //k = 0 ~ until  a[j] > a[i]
        temp[k++] = a[i];
        //push left
        cross += j-m;
    }

    for(k=left;k<j;++k){
        a[k] = temp[k-left];
    }
    return w+cross;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    cout << inv(a, 0, n);
}
//nlog^2(n)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL inv(int ar[], int left, int right){
    int j, mid = (left+right)/2;
    int cross;
    if(left+1>=right) return 0;
    LL w = inv(ar, left, mid) + inv(ar, mid, right);
    sort(ar+mid, ar+right);
    for(int i=left;i<mid;++i){
        cross += lower_bound(ar+mid, ar+right, ar[i] - (ar+mid));

    }
    return w + cross;
}
int main(){
    int n;
    cin >> n;
    int a[100001];
    for(int i=0;i<n;++i) cin >> a[i];
    cout << inv(a, 0, n);
}
