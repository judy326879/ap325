#include <bits/stdc++.h>
#define N 100010
typedef long long LL;
using namespace std;
vector<LL> adj[N+1], len(N+1), num(N+1);
            //child, length  , 經過次數
LL count(int v){
    int h = 1;//itself
    for(auto u:adj[v]){
        h += count(u);
    }
    num[v] = h;
    return num[v];
}
int main(){
    int n, v;
    cin >> n;
    for(int i=2;i<=n;++i){
        cin >> v;
        adj[v].push_back(i);
    }
    for(int i=2;i<=n;++i) cin >> len[i];
    count(1);
    LL sum = 0, k;
    for(int i=1;i<=n;++i){
        k = num[i]*(n-num[i]);
        sum += k*len[i];
    }
    cout << 2*sum << endl;
    //來回
}
