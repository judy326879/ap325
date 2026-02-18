#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int n;
LL p = 1000000009;
LL m[101] = {};
LL c(int i){
    if(m[i]>=0) return m[i];
    LL sum = 0;
    for(int i1=0;i1<i;++i1){       //sigma
        LL t =(c(i1)*c(i-1-i1))%p;//遞迴
        sum = (sum+t)%p;
    };
    return m[i] = sum;
}
int main(){
    cin >> n;
    for(int i=1;i<=n;++i) m[i] = -1;
    m[0] = 1;
    cout << c(n) << endl;
}
