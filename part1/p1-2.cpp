#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
long long p[50010];
long long cut(int u, int v){
    if(v-u<=1) return 0;
    long long k = (p[v]+p[u])/2;
    int m = lower_bound(p+u, p+v, k)-p;//位置-起始 = 索引值 i
    if(p[m-1]-p[u]>=p[v]-p[m]) --m;
    return p[v] - p[u] + cut(u, m) + cut(m, v);
}
int main(){
    cin >> n >> m;
    p[0] = 0;
    p[n+1] = m;
    for(int i=1;i<=n;++i){
        cin >> p[i];
    }
    cout << cut(0, n+1);
}
