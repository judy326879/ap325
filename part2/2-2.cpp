#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int distinct(int from[], int to[], int n){
    if(n<1) return 0;
    vector<int> v(from, from+n);
    sort(v.begin(), v.end());
    to[0] = v[0];
    int num = 1;
    for(int i=1;i<n;++i){
        if(v[i]!=v[i-1]){
            to[num++] = v[i];
        }
    }
    return num;
}
int main(){
    int a[100010], b[100010], n, k;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    k = distinct(a, b, n);
    for(int i=0;i<n;++i){
        a[i] = lower_bound(b, b+k, a[i]) - b;
    }
    k = distinct(a, b, n);
    for(int i=0;i<n;++i){
        cout << a[i] << " ";
    }
}
