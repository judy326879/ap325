#include <bits/stdc++.h>
#define N 1000000
using namespace std;
vector<int> p(N), c(N);
int dp(int m, int n){
    if(c[m]>=0) return c[m];//avoid重複計算
    int imax = 0;
    for(int i=0;i<n;++i){
        if(m & (1<<i)){//m的第i個位元為1
            int k = dp(m^(1<<i), n);
            if(k>imax) imax = k;//max值
        }
    }
    c[m] = imax+p[m];//前置最佳解 + 該點權重
    return c[m];
}
int main(){
    int n;
    cin >> n;
    int m = 1 << n;//m = 2^n
    for(int i=0;i<m;++i){
        cin >> p[i];
        c[i] = -1;
    }
    c[0] = p[0];
    cout << dp(m-1, n);//m的二進位全為1, until m = 0
}
