#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
int n, k, p[50010], po[50010] = {}, ne[50010] = {};
long long cut(int left, int right, int k1){
    if(right-left<2) return 0;
    if(k1<=0) return 0;
    long long cost = 0;
    int Min = INT_MAX, ip = 0;
    for(int i=left+1;i<right;++i){
        if(i == left+1){
            cost += po[left] - po[left-1];
            for(int j=right;j>i;--j) cost -= ne[j] - ne[right+1];
        }
        else{
            cost += po[i-1] - po[left-1];
            cost += ne[i] - ne[right+1];
        }
        if(abs(cost)<Min){
            ip = i;
            Min = abs(cost);
        }
    }
    return p[ip] + cut(left, ip-1, k1-1) + cut(ip+1, right, k1-1);
}
int main(){
    cin >> n >> k;
    p[0] = 0;
    po[0] = 0;
    ne[n+1] = 0;
    for(int i=1;i<=n;++i){
        cin >> p[i];
        po[i] = po[i-1]+p[i];
    }
    for(int i=n;i>0;--i){
        ne[i] = ne[i+1] + p[i];
    }
    cout << cut(1, n, k) << endl;
}
