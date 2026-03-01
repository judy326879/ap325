#include <bits/stdc++.h>
#define N 10005
using namespace std;
vector<int> p(N);
int find(int v){
    if(p[v]<0) return v;
    return p[v] = find(p[v]);
}
struct Edge{
    int u, v, w;
};
bool cmp(Edge &p, Edge &q){
    return p.w < q.w;
}
bool joint(int u, int v){
    int f1 = find(u), f2 = find(v);
    //同parent -> 無法圍成圓
    if(f1 == f2) return 0;
    if(p[f1]<p[f2]){
        p[f1] += p[f2];
        p[f2] = f1;
    }
    else{
        p[f2] += p[f1];
        p[f1] = f2;
    }
    return 1;
}
int main(){
    int n, m, u, v, t;
    cin >> n >> m;
    vector<Edge> edge;
    for(int i=0;i<m;++i){
        cin >> u >> v >> t;
        edge.push_back({u, v, t});
    }
    for(int i=0;i<n;++i) p[i] = -1;
    sort(edge.begin(), edge.end(), cmp);
    int cost = 0, nedge = 0;
    for(Edge e:edge){
        if(joint(e.u, e.v)){
            cost+=e.w;
            nedge++;
        }
    }
    if(nedge<n-1) cout << -1 << endl;
    else cout << cost << endl;
}
