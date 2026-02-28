//Dijkstra
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    vector<int> d(n), parent(n);
    vector<bool> done(n, 0);
    priority_queue<pair<int, int>> pq;
    int u, v, t;
    for(int i=0;i<m;++i){
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    int source = 0;
    for(int i=0;i<n;++i) d[i] = INT_MAX;
    for(int i=0;i<n;++i) parent[i] = -1;
    d[source] = 0;
    pq.push({d[source], source});

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if(done[v]) continue;
        done[v] = 1;

        for(auto e:adj[v]){
            int u = e.first, w = e.second;
            if(d[v]+w<d[u]){
                d[u] = d[v] + w;
                parent[u] = v;
                pq.push({-d[u], u});
            }
        }
    }
    int Max = -1, cnt = 0, far;
    for(int i=0;i<n;++i){
        if(d[i]<INT_MAX){
            if(d[i]>Max){
                Max = d[i];
                far = i;
            }
        }
        else cnt++;
    }
    cout << Max << '\n' << cnt;
}
