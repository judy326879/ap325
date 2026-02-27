#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<pair<int, int>> adj[n];
    //點 i 有多少個 from
    vector<int> indeg(n, 0);
    int from, to, w;
    for(int i=0;i<m;++i){
        cin >> from >> to >> w;
        adj[from].push_back({to, w});
        indeg[to]++;
    }
    queue<int> q;
    // min / max
    vector<int> d(n, 1000000001), p(n, -1000000001);
    int cnt = 0;
    d[s] = p[s] = 0;//起點
    for(int i=0;i<n;++i){
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cnt++;
        for(auto a:adj[v]){
            if(d[v] < 1000000001){
                d[a.first] = min(d[a.first], d[v]+a.second);
                p[a.first] = max(p[a.first], p[v]+a.second);
            }
            //可到達 -> 放入 q
            if(--indeg[a.first] == 0) q.push(a.first);
        }
    }
    if(d[t] == 1000000001) cout << "No path\nNo path";
    else cout << d[t] << '\n' << p[t];
}
