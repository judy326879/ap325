#include <bits/stdc++.h>
#define N 100010
using namespace std;
//d1[i]  在 i 被挑選下最佳解
//d01[i] 在 i 沒被挑選 被管轄下下最佳解(=至少一個 i 的孩子被挑選)
//d00[i] 在 i 不被挑選 不一定被管轄下最佳解
vector<int> d01(N, 0), d1(N, 0), w(N, 0), d00(N, 0);
vector<int> adj[N];
//present, parent
void dfs(int r, int p){
    d1[r] = w[r], d01[r] = INT_MAX, d00[r] = 0;
    for(int v:adj[r]){// v -> child(except parent)
        if(v == p) continue;
        dfs(v, r);
        d1[r] += min(d00[v], d1[v]);//不含v / 含v
        d00[r]+= min(d1[v], d01[v]);
        d01[r] = min(d01[r], d1[v]-d01[v]);
    }
    d01[r] = d00[r] + max(0, d01[r]);
    return ;
}
int main(){
    int n, u, v;
    cin >> n;
    for(int i=1;i<=n;++i) cin >> w[i];
    for(int i=1;i<n;++i){
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(1, 0);
    cout << min(d1[1], d01[1]);
}
